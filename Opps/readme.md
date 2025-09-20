# OOPs — Good Notes (4 Pillars)

> Short, pointwise notes for quick revision. Copy-paste into your `.md` file.

---

## What is OOPs?

* **Object-Oriented Programming (OOP)** is a programming paradigm based on **objects** (data + behaviour).
* Focuses on **modularity**, **reusability**, **extensibility** and **abstraction**.

---

# Pillar 1 — Encapsulation

### Classes & Objects

* **Class**: blueprint that defines data (attributes) and functions (methods).
* **Object**: runtime instance of a class with actual values.
* **Example (conceptual)**: `class Car { speed, accel; void drive(); }` → `Car myCar;`

### Access Modifiers (visibility)

* **public**: accessible everywhere.
* **protected**: accessible inside class and derived classes.
* **private**: accessible only inside the class itself.

### Constructors

* **Constructor**: special member function invoked when an object is created.
* Characteristics: same name as class, no return type.

**Types of constructors**

1. **Default / Non-parameterized constructor**

   * No parameters.
   * Example: `ClassName() { /* init */ }`.
2. **Parameterized constructor**

   * Takes arguments to initialize members.
   * Example: `ClassName(int x) { this->x = x; }`.
3. **Copy constructor**

   * Initializes a new object using an existing object: `ClassName(const ClassName &other)`.
   * Called on object initialization like `ClassName b = a;`.

### Shallow vs Deep Copy

* **Shallow copy**

  * Copies member values as-is (including pointers), so both objects share the same dynamically allocated memory.
  * Problem: double-free, unintended shared state.
* **Deep copy**

  * Allocates separate memory and duplicates the pointed-to data; objects are independent.
  * Implement in copy constructor and assignment operator when class manages dynamic resources.

---

# Pillar 2 — Inheritance

### What is Inheritance?

* Mechanism to create a new class (derived) from an existing class (base), reusing and extending behavior.
* Promotes code reuse and models "is-a" relationships.

### Mode of inheritance (C++ style)

* Inheritance can be declared with access specifiers: `public`, `protected`, `private`.

| Mode        | `public` members in derived | `protected` members in derived | `private` members in derived |
| ----------- | --------------------------- | ------------------------------ | ---------------------------- |
| `public`    | remain `public`             | remain `protected`             | inaccessible                 |
| `protected` | become `protected`          | remain `protected`             | inaccessible                 |
| `private`   | become `private`            | become `private`               | inaccessible                 |

> Note: `private` members of base are never directly accessible in derived classes.

### Types of inheritance

* **Single inheritance**: one base, one derived. (`class B : public A`)
* **Multiple inheritance**: a derived class inherits from more than one base. (`class C : public A, public B`)
* **Multilevel inheritance**: chain of inheritance (A → B → C).
* **Hierarchical inheritance**: one base, many derived classes.
* **Hybrid inheritance**: combination of two or more types (may involve multiple and multilevel).

---

# Pillar 3 — Polymorphism

### What is Polymorphism?

* Ability of entities (functions/objects) to take multiple forms.
* Two main kinds: **compile-time (static)** and **runtime (dynamic)**.

### Compile-time Polymorphism (Static)

* Resolved at compile time.
* **Function overloading**

  * Multiple functions with same name but different parameters in the same scope.
  * Compiler chooses appropriate function based on argument types/count.
* **Constructor overloading**

  * Multiple constructors with different parameter lists.
* **Operator overloading**

  * Define or redefine behavior of operators for user-defined types (e.g., `operator+`, `operator==`).
  * Use sparingly—keep semantics intuitive.

### Runtime Polymorphism (Dynamic)

* Resolved at runtime via **late binding**.
* Achieved using **virtual functions** and **inheritance**.
* **Function overriding**

  * Derived class provides its own implementation of a base class virtual function.
  * Signature must match (or be covariant where allowed).
* **Virtual function**

  * Declared in base using `virtual returnType func(args);`.
  * Enables calling derived implementations through base pointers/references.
* **Pure virtual function & Abstract class**

  * Pure virtual: `virtual void f() = 0;` → forces derived classes to implement.
  * A class with at least one pure virtual function is **abstract** and cannot be instantiated.

---

# Pillar 4 — Abstraction

### What is Abstraction?

* Hiding complex implementation details and exposing a simpler interface.
* Emphasizes *what* an object does rather than *how* it does it.

### Abstract Class & Interface

* **Abstract class**: contains one or more pure virtual functions; cannot create instances.
* **Purpose**: define an interface for derived classes and provide optional default behavior.

```cpp
// Example abstract class (C++)
class Shape {
public:
    virtual double area() const = 0; // pure virtual
    virtual ~Shape() {}
};
```

---

# Additional: `static` keyword (common usage in C++)

* **static member variable**

  * Single copy shared by all objects of the class.
  * Declared inside class; defined (and optionally initialized) outside: `int Class::x = 0;`.
* **static member function**

  * Can be called without an object: `Class::func()`.
  * Cannot access non-static members directly.
* **static local variable**

  * Static lifetime—retains value across function calls but limited to function scope.
* **static at global/file scope**

  * Restricts visibility to the translation unit (internal linkage).

---

# Quick Tips / Best Practices

* Use encapsulation to protect invariants and hide implementation details.
* Prefer composition over inheritance unless modeling an `is-a` relationship.
* Implement deep copy if your class manages dynamic memory or resources.
* Keep operator overloads intuitive and consistent with built-in types.
* Mark base destructors `virtual` if the class is meant to be a polymorphic base.
* Use `override` keyword (C++11+) when overriding virtual functions to catch signature errors.

---

# Short Glossary

* **Object**: instance of a class.
* **Method**: function defined inside a class.
* **Member**: attribute or method of a class.
* **Interface**: pure-virtual-only abstract class (in C++ style).
* **vtable**: runtime table to support virtual function dispatch (language implementation detail).

---

*End of notes.*
