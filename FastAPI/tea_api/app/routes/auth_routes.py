from datetime import timedelta
from fastapi import APIRouter, HTTPException, Depends, status
from fastapi.security import OAuth2PasswordBearer, OAuth2PasswordRequestForm
from app.schemas.user_schema import UserCreate, Token
from app.services.auth_service import (
    get_user_by_username,
    get_user_by_email,
    create_user,
    authenticate_user,
)
from app.utils.jwt_handler import create_access_token, decode_access_token
from app.config import settings

router = APIRouter()
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="/auth/login")


@router.post("/register", status_code=status.HTTP_201_CREATED)
async def register(user: UserCreate):
    if await get_user_by_username(user.username):
        raise HTTPException(status_code=400, detail="Username already exists")
    if await get_user_by_email(user.email):
        raise HTTPException(status_code=400, detail="Email already exists")
    created_user = await create_user(user.model_dump())
    return {
        "username": created_user["username"],
        "email": created_user["email"],
        "message": "User created successfully",
    }


@router.post("/login", response_model=Token)
async def login(form_data: OAuth2PasswordRequestForm = Depends()):
    user = await get_user_by_username(form_data.username)
    if not authenticate_user(user, form_data.password):
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Invalid username or password",
            headers={"WWW-Authenticate": "Bearer"},
        )

    access_token = create_access_token(
        data={"sub": user["username"]},
        expires_delta=timedelta(minutes=settings.access_token_expire_minutes),
    )
    return {"access_token": access_token, "token_type": "bearer"}


async def get_current_user(token: str = Depends(oauth2_scheme)):
    try:
        payload = decode_access_token(token)
        username: str | None = payload.get("sub")
        if username is None:
            raise HTTPException(status_code=401, detail="Could not validate credentials")
        user = await get_user_by_username(username)
        if user is None:
            raise HTTPException(status_code=401, detail="User not found")
        return user
    except ValueError:
        raise HTTPException(status_code=401, detail="Invalid or expired token")
