from bson import ObjectId
from app.database import tea_collection


def serialize_tea(doc: dict) -> dict:
    return {
        "id": str(doc["_id"]),
        "name": doc["name"],
        "origin": doc["origin"],
        "price": doc["price"],
        "description": doc.get("description"),
    }


async def get_all_teas():
    teas = []
    async for tea in tea_collection.find():
        teas.append(serialize_tea(tea))
    return teas


async def get_tea_by_id(tea_id: str):
    tea = await tea_collection.find_one({"_id": ObjectId(tea_id)})
    return serialize_tea(tea) if tea else None


async def create_tea(tea_data: dict):
    result = await tea_collection.insert_one(tea_data)
    created = await tea_collection.find_one({"_id": result.inserted_id})
    return serialize_tea(created)


async def update_tea(tea_id: str, tea_data: dict):
    await tea_collection.update_one({"_id": ObjectId(tea_id)}, {"$set": tea_data})
    updated = await tea_collection.find_one({"_id": ObjectId(tea_id)})
    return serialize_tea(updated) if updated else None


async def delete_tea(tea_id: str):
    tea = await tea_collection.find_one({"_id": ObjectId(tea_id)})
    if not tea:
        return None
    await tea_collection.delete_one({"_id": ObjectId(tea_id)})
    return serialize_tea(tea)
