from fastapi import FastAPI
from app.routes.tea_routes import router as tea_router
from app.routes.auth_routes import router as auth_router

app = FastAPI(
    title="Tea API",
    description="FastAPI project with MongoDB, JWT authentication, and CRUD operations.",
    version="1.0.0",
)

app.include_router(auth_router, prefix="/auth", tags=["Auth"])
app.include_router(tea_router, prefix="/teas", tags=["Teas"])


@app.get("/")
def read_root():
    return {"message": "Welcome to Tea API"}
