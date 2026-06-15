# FastAPI Crash Course in Hindi — Structured Notes

**Source:** FastAPI crash course in Hindi (Chai aur Code)

---

## 1. Introduction to FastAPI

### What is FastAPI?
FastAPI is a **modern, high-performance Python web framework** designed specifically for building APIs quickly and efficiently.

### Why FastAPI?
- Fast and lightweight
- Easy to learn and use
- Built around Python type hints
- Automatically generates API documentation
- Commonly used for:
  - Backend development
  - Machine Learning model deployment
  - Data Science applications
  - Microservices

### Framework Comparison
FastAPI gives a Python developer experience similar to what Express.js gives in Node.js. It is often preferred for pure API development because it is efficient and simple.

### Industry Importance
FastAPI has become an important skill for:
- Data Scientists
- Machine Learning Engineers
- Python Web Developers

It is widely used for deploying models and building API-based applications.

---

## 2. Core Ecosystem and Dependencies

FastAPI works best with a few important supporting tools.

### Uvicorn
- A high-performance **ASGI server** used to run FastAPI applications
- Handles requests and serves the API
- Commonly used as the runtime for FastAPI projects

### Pydantic
- A data validation and parsing library
- Ensures incoming request data matches the expected structure and types
- Helps enforce type safety in Python web applications
- Similar in purpose to TypeScript for JavaScript in terms of type checking and structure

### Typing Module
- Python’s built-in `typing` module is used for type hints
- Helps with autocomplete, readability, and type checking
- Example: `List`

---

## 3. Project Environment Setup

### Create a Virtual Environment
A virtual environment keeps project dependencies isolated from the global Python installation.

```bash
python3 -m venv venv
```

You can also use names like `api` or `.venv`.

### Activate the Environment
**Linux / macOS**
```bash
source venv/bin/activate
```

**Windows**
```powershell
venv\Scripts\activate
```

### Install Required Packages
```bash
pip install fastapi uvicorn
```

### Save Dependencies
```bash
pip freeze > requirements.txt
```

This helps others recreate the same environment later.

---

## 4. Code Initialization and Data Models (`main.py`)

### Essential Imports
```python
from fastapi import FastAPI
from pydantic import BaseModel
from typing import List
```

### Create the Application Instance
```python
app = FastAPI()
```

### Define a Pydantic Model
A Pydantic model defines the structure and validation rules for data.

```python
class Tea(BaseModel):
    id: int
    name: str
    origin: str
```

### Mock Database
In this crash course, no real database is used. Instead, data is stored in memory using a list.

```python
teas: List[Tea] = []
```

---

## 5. FastAPI Routing and Decorators

### What is a Decorator?
Decorators are special Python syntax that modify or extend the behavior of functions.

In FastAPI, decorators turn normal functions into API endpoints.

Examples:
- `@app.get()`
- `@app.post()`
- `@app.put()`
- `@app.delete()`

---

## 6. CRUD Operations

CRUD stands for:
- **Create**
- **Read**
- **Update**
- **Delete**

### 6.1 Read — Home Route
This route returns a welcome message.

```python
@app.get("/")
def read_root():
    return {"message": "Welcome to chai code"}
```

### 6.2 Read — Get All Items
This route returns the full list of teas.

```python
@app.get("/teas")
def get_teas():
    return teas
```

### 6.3 Create — Add a New Tea
This route receives a `Tea` object, validates it with Pydantic, and adds it to the list.

```python
@app.post("/teas")
def add_tea(tea: Tea):
    teas.append(tea)
    return tea
```

### 6.4 Update — Modify an Existing Tea
This route updates a tea item using its ID.

```python
@app.put("/teas/{tea_id}")
def update_tea(tea_id: int, updated_tea: Tea):
    for index, tea in enumerate(teas):
        if tea.id == tea_id:
            teas[index] = updated_tea
            return updated_tea
    return {"error": "Tea not found"}
```

#### Key Concepts in Update
- **Path Parameters**: `tea_id` is taken from the URL
- **Request Body**: `updated_tea` comes from the JSON payload
- **enumerate()**: used to get both index and item
- **List replacement**: the matched item is overwritten in the list

### 6.5 Delete — Remove a Tea
This route deletes a tea by ID.

```python
@app.delete("/teas/{tea_id}")
def delete_tea(tea_id: int):
    for index, tea in enumerate(teas):
        if tea.id == tea_id:
            return teas.pop(index)
    return {"error": "Tea not found"}
```

#### Key Concepts in Delete
- **Path Parameters**: `tea_id` comes from the URL
- **enumerate()**: used to find the index
- **pop()**: removes and returns the matched item

---

## 7. Running the Server

FastAPI applications are run using Uvicorn.

```bash
uvicorn main:app --reload
```

### Meaning of the Command
- `main` → the file name `main.py`
- `app` → the FastAPI instance
- `--reload` → automatically restarts the server when code changes

---

## 8. Automatic Interactive Documentation

One of FastAPI’s biggest advantages is automatic documentation generation.

### Swagger UI
Open the following in your browser:

```text
http://127.0.0.1:8000/docs
```

### What Swagger UI Provides
- Interactive API testing
- Endpoint listing
- Request body input
- Response preview
- Built-in execution of requests

### Why It Is Useful
You can test APIs directly from the browser without needing external tools like Postman.

### Schemas
FastAPI reads Pydantic models and automatically generates schemas.

This helps with:
- Validation
- Clear API structure
- Better developer experience
- Auto-generated request and response documentation

---

## 9. Important Technical Terms

- FastAPI
- API
- REST API
- Uvicorn
- ASGI
- Pydantic
- BaseModel
- Typing
- Type hints
- Virtual environment
- `venv`
- `pip`
- `requirements.txt`
- Decorators
- Routing
- GET
- POST
- PUT
- DELETE
- Path parameters
- Request body
- JSON
- `enumerate()`
- `pop()`
- Swagger UI
- Automatic documentation
- Schema validation

---

## 10. Complete Learning Flow

**FastAPI → Uvicorn → Pydantic → Virtual Environment → App Initialization → Data Model Creation → Routing → CRUD Operations → Server Execution → Swagger Documentation**

This is the full workflow shown in the crash course and forms a strong foundation for building APIs with FastAPI.


```bash
## Full Application
tea_api/
│
├── app/
│   ├── main.py
│   ├── database.py
│   ├── models/
│   │   ├── tea.py
│   │   └── user.py
│   │
│   ├── schemas/
│   │   ├── tea_schema.py
│   │   └── user_schema.py
│   │
│   ├── routes/
│   │   ├── tea_routes.py
│   │   └── auth_routes.py
│   │
│   ├── services/
│   │   ├── tea_service.py
│   │   └── auth_service.py
│   │
│   ├── utils/
│   │   ├── hash.py
│   │   └── jwt_handler.py
│   │
│   └── config.py
│
├── requirements.txt
├── .env
└── README.md
```