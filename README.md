---

# README

---

## Русская версия

# Мой первый CRUD-проект на C++

Это мой первый проект с реализацией CRUD-операций (Create, Read, Update, Delete) на языке C++. В этом проекте используется веб-фреймворк Crow, база данных PostgreSQL и управление конфигурацией через dotenv.

---

### О проекте

Приложение — простой REST API для управления задачами (tasks). Можно создавать задачи, получать список всех задач, а также расширять функционал.

---

### Технологии

* **C++20** — язык программирования
* **Crow** — легковесный C++ веб-фреймворк
* **PostgreSQL** — реляционная база данных
* **libpqxx** — C++ клиент для PostgreSQL
* **dotenv-cpp** — загрузка переменных окружения из `.env`
* **CMake** — сборка проекта

---

### Установка и запуск

1. Клонируйте репозиторий:

   ```bash
   git clone <URL_репозитория>
   cd crow_task_manager
   ```
2. Создайте и заполните `.env` файл с настройками подключения к базе, например:

   ```
   DB_HOST=localhost
   DB_PORT=5432
   DB_NAME=taskdb
   DB_USER=postgres
   DB_PASS=your_password
   ```
3. Убедитесь, что PostgreSQL запущен и создана таблица `tasks`:

   ```sql
   CREATE TABLE tasks (
       id SERIAL PRIMARY KEY,
       title TEXT NOT NULL
   );
   ```
4. Соберите проект:

   ```bash
   mkdir build
   cd build
   cmake ..
   make -j
   ```
5. Запустите сервер:

   ```bash
   ./task_manager
   ```
6. API доступен по адресу: `http://localhost:18080`

---

### Примеры запросов

* Получить список задач:
  `GET /tasks`

* Добавить задачу:
  `POST /task/add` с JSON телом:

  ```json
  {
    "title": "Новая задача"
  }
  ```

---

### Лицензия

Этот проект открыт и бесплатен для использования.

---

## English Version

# My First CRUD Project in C++

This is my first project implementing CRUD operations (Create, Read, Update, Delete) in C++. It uses the Crow web framework, PostgreSQL database, and dotenv for configuration management.

---

### About the Project

A simple REST API application for task management. You can create tasks, retrieve the list of all tasks, and extend the functionality as needed.

---

### Technologies Used

* **C++20** — programming language
* **Crow** — lightweight C++ web framework
* **PostgreSQL** — relational database
* **libpqxx** — C++ client library for PostgreSQL
* **dotenv-cpp** — environment variables loader from `.env` file
* **CMake** — build system

---

### Installation and Running

1. Clone the repository:

   ```bash
   git clone <repository_url>
   cd crow_task_manager
   ```
2. Create and fill the `.env` file with your database settings, for example:

   ```
   DB_HOST=localhost
   DB_PORT=5432
   DB_NAME=taskdb
   DB_USER=postgres
   DB_PASS=your_password
   ```
3. Make sure PostgreSQL is running and the `tasks` table is created:

   ```sql
   CREATE TABLE tasks (
       id SERIAL PRIMARY KEY,
       title TEXT NOT NULL
   );
   ```
4. Build the project:

   ```bash
   mkdir build
   cd build
   cmake ..
   make -j
   ```
5. Run the server:

   ```bash
   ./task_manager
   ```
6. The API will be available at: `http://localhost:18080`

---

### Example Requests

* Get the list of tasks:
  `GET /tasks`

* Add a new task:
  `POST /task/add` with JSON body:

  ```json
  {
    "title": "New task"
  }
  ```

---

### License

This project is open and free to use.

---
