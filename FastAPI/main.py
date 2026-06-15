from fastapi import FastAPI
from pydantic import BaseModel
from typing import List

# Initialize the FastAPI application
app = FastAPI()

# Define the Data Model using Pydantic
class Tea(BaseModel):
    id: int
    name: str
    origin: str

# Mock Database (In-memory list)
teas: List[Tea] = []

# READ - Home Route
@app.get("/")
def read_root():
    return {"message": "Welcome to chai code"}

# READ - Get all Teas
@app.get("/teas")
def get_teas():
    return teas

# CREATE - Add a new Tea
@app.post("/teas")
def add_tea(tea: Tea):
    teas.append(tea)
    return tea

# UPDATE - Edit an existing Tea by ID
@app.put("/teas/{tea_id}")
def update_tea(tea_id: int, updated_tea: Tea):
    for index, t in enumerate(teas):
        if t.id == tea_id:
            teas[index] = updated_tea
            return updated_tea
            
    # Return error if loop finishes without finding the ID
    return {"error": "Tea not found"}

# DELETE - Remove a Tea by ID
@app.delete("/teas/{tea_id}")
def delete_tea(tea_id: int):
    for index, t in enumerate(teas):
        if t.id == tea_id:
            deleted = teas.pop(index)
            return deleted
            
    # Return error if loop finishes without finding the ID
    return {"error": "Tea not found"}