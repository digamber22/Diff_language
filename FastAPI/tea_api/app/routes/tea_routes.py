from fastapi import APIRouter, HTTPException, Depends
from app.schemas.tea_schema import TeaCreate, TeaResponse
from app.services.tea_service import (
    get_all_teas,
    get_tea_by_id,
    create_tea,
    update_tea,
    delete_tea,
)
from app.routes.auth_routes import get_current_user

router = APIRouter()


@router.get("/", response_model=list[TeaResponse])
async def read_teas(current_user: dict = Depends(get_current_user)):
    return await get_all_teas()


@router.get("/{tea_id}", response_model=TeaResponse)
async def read_tea(tea_id: str, current_user: dict = Depends(get_current_user)):
    tea = await get_tea_by_id(tea_id)
    if not tea:
        raise HTTPException(status_code=404, detail="Tea not found")
    return tea


@router.post("/", response_model=TeaResponse, status_code=201)
async def create_new_tea(tea: TeaCreate, current_user: dict = Depends(get_current_user)):
    return await create_tea(tea.model_dump())


@router.put("/{tea_id}", response_model=TeaResponse)
async def edit_tea(tea_id: str, tea: TeaCreate, current_user: dict = Depends(get_current_user)):
    updated = await update_tea(tea_id, tea.model_dump())
    if not updated:
        raise HTTPException(status_code=404, detail="Tea not found")
    return updated


@router.delete("/{tea_id}", response_model=TeaResponse)
async def remove_tea(tea_id: str, current_user: dict = Depends(get_current_user)):
    deleted = await delete_tea(tea_id)
    if not deleted:
        raise HTTPException(status_code=404, detail="Tea not found")
    return deleted
