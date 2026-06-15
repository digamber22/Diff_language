from app.database import user_collection
from app.utils.hash import hash_password, verify_password


async def get_user_by_username(username: str):
    return await user_collection.find_one({"username": username})


async def get_user_by_email(email: str):
    return await user_collection.find_one({"email": email})


async def create_user(user_data: dict):
    user_data["hashed_password"] = hash_password(user_data.pop("password"))
    user_data["disabled"] = False
    result = await user_collection.insert_one(user_data)
    return await user_collection.find_one({"_id": result.inserted_id})


def authenticate_user(user: dict | None, password: str):
    if not user:
        return False
    return verify_password(password, user["hashed_password"])
