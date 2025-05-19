# 🚍 Red Bus Route Finder (Dijkstra's Algorithm)

A C++ based Red Bus route simulation project for university-level **Data Structures and Algorithms (DSA)** coursework. This console-based application uses **Dijkstra's Algorithm** to determine the shortest path between predefined bus stations. It leverages core DSA concepts such as **Graphs**, **Linked Lists**, and **File Handling** for efficient route calculation and data persistence.

---

## 🔧 Features

* 📍 **Predefined Bus Stations** – Represents a real-world static network of stops.
* 📡 **Shortest Path Finder** – Utilizes **Dijkstra’s Algorithm** to find the shortest route.
* 📄 **File Handling** – Reads and stores route data from files.
* 🧱 **Data Structures Used**:

  * **Adjacency List** using **Linked Lists** (Graph Representation)
  * **Min Heap** for Dijkstra's priority queue
  * **File Streams** for persistent storage

---

## 📂 Project Structure

```
RedBusRoute/
├── main.cpp
├── graph.cpp
├── graph.h
├── stations.txt           // List of predefined stations
├── distances.txt          // Adjacency list/weights
├── README.md
```

---

## 🚀 How to Run

### 🖥 Prerequisites

* C++ Compiler (GCC recommended)
* Any IDE (e.g., CodeBlocks, VS Code) or command-line interface

### ▶️ Steps

1. Clone or download this repository.
2. Open the project folder in your IDE or terminal.
3. Compile the program:

   ```bash
   g++ main.cpp graph.cpp -o redbus
   ```
4. Run the executable:

   ```bash
   ./redbus
   ```
5. Follow the on-screen instructions to input source and destination stations.

---

## 📘 Example Usage

```
Enter source station: A
Enter destination station: D

Shortest route: A -> B -> D
Total distance: 12 km
```

---

## 💡 Learning Outcomes

* Understanding and implementation of **Graph algorithms**
* Hands-on with **Dijkstra’s Algorithm**
* Use of **Linked Lists** for dynamic graph representation
* Practical use of **file I/O** in C++
* Structuring and managing modular C++ projects

---

## 🧠 Algorithms & Concepts Applied

* ✅ Graphs (Adjacency List)
* ✅ Dijkstra's Shortest Path Algorithm
* ✅ Linked Lists
* ✅ File Streams (ifstream/ofstream)
* ✅ Priority Queue using Min Heap

---

## 📜 License

This project is intended for academic learning and demonstration purposes.

---

## Created by:
21K4568 Muhammad Ali k214568@nu.edu.pk
---
21K3323 Muhammad Shaheer k213323@nu.edu.pk
---
K213175 Syed Muhammad Taqi k213175@nu.edu.pk
---
