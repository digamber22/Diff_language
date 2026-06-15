from pydantic import BaseModel, EmailStr


class User(BaseModel):
    username: str
    email: EmailStr
    password: str


class UserInDB(BaseModel):
    username: str
    email: EmailStr
    hashed_password: str
    disabled: bool = False
