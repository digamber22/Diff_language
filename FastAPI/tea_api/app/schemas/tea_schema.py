from pydantic import BaseModel, Field
from typing import Optional


class TeaCreate(BaseModel):
    name: str = Field(..., min_length=1)
    origin: str = Field(..., min_length=1)
    price: float = Field(..., gt=0)
    description: Optional[str] = None


class TeaResponse(TeaCreate):
    id: str
