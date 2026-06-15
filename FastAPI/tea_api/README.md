# Tea API

FastAPI project with MongoDB, JWT authentication, password hashing, and CRUD endpoints.

## Features
- User registration
- JWT login
- Protected tea CRUD routes
- MongoDB storage
- Swagger documentation

## Setup

```bash
python -m venv venv
source venv/bin/activate
pip install -r requirements.txt
uvicorn app.main:app --reload
```

## API Docs
- Swagger UI: `/docs`
- ReDoc: `/redoc`

## Environment Variables
Create a `.env` file with:
- `MONGODB_URL`
- `DATABASE_NAME`
- `SECRET_KEY`
- `ALGORITHM`
- `ACCESS_TOKEN_EXPIRE_MINUTES`

## Notes
- The tea endpoints are protected by JWT.
- The login endpoint uses `OAuth2PasswordRequestForm`.
- MongoDB collections are `teas` and `users`.
