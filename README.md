# hft-simulation-engine

Mini high-frequency trading system that simulates a real exchange connection, processes live-like market data, maintains an order book, and sends/receives orders — all while optimizing for speed, concurrency, and precision

---

# 🚀 Development Roadmap for HFT Simulation Project

## 🧭 Overall Goals:

- Learn low-level TCP/UDP networking
- Implement multithreading, concurrency, and shared memory safely
- Build a simplified but realistic trading system with measurable latency

---

## 📅 Phase 1: Foundations (Week 1–2)

### 🔹 Objectives:

- Learn basics of raw networking (sockets)
- Set up a fast C++ development workflow
- Implement your first TCP and UDP servers

### ✅ Tasks:

- Set up C++ build system (CMake + clang++)
- Create a basic TCP server that accepts connections and logs messages
- Create a basic UDP server that listens to messages (simulate market data)
- Learn `select()`, `poll()`, and blocking vs non-blocking sockets

### 🔧 What You’ll Use:

- C++
- POSIX sockets (`socket()`, `bind()`, `recvfrom()`, etc.)
- `std::thread` or raw `pthread`

---

## 📅 Phase 2: Market Data Feed & Order Gateway (Week 3–4)

### 🔹 Objectives:

- Simulate a feed of market data (via UDP)
- Accept trading orders (via TCP)
- Learn how real exchanges communicate

### ✅ Tasks:

- Implement a UDP "market data simulator" that sends fake price ticks every 100ms
- Write a feed handler that parses and stores this data
- Build a TCP order receiver: accepts orders like “BUY AAPL 100.50 50”
- Log or print acknowledgments

### 🔧 New Concepts:

- Serialization/deserialization of messages
- Message framing, fixed-size buffers
- Network performance tradeoffs (packet size, batching)

---

## 📅 Phase 3: In-Memory Order Book (Week 5–6)

### 🔹 Objectives:

- Create a fast in-memory data structure to hold the order book
- Integrate with your market data feed

### ✅ Tasks:

- Use `std::map` or `std::priority_queue` to implement bids/asks
- Store state for top-of-book (best bid/ask)
- Update this state based on incoming market data messages
- Print spread, mid price, etc.

### 🔧 You’ll Learn:

- Cache-friendly data layouts
- Delta updates vs full snapshots
- Concurrency issues with shared data

---

## 📅 Phase 4: Multithreading & Event Loop (Week 7–8)

### 🔹 Objectives:

- Run components in parallel threads (feed, gateway, strategy)
- Avoid blocking and race conditions

### ✅ Tasks:

- Use `std::thread` or a thread pool to isolate modules
- Synchronize access to the order book using `std::mutex` or `std::atomic`
- Implement message queues or ring buffers between threads

### 🔧 Concepts:

- Thread lifecycle
- Shared vs message-passing concurrency
- Lock contention, false sharing

---

## 📅 Phase 5: Strategy Engine (Week 9–10)

### 🔹 Objectives:

- Build a simple trading strategy
- React to price movements or spreads

### ✅ Tasks:

- Monitor bid/ask spread and trigger a “quote” or “order”
- Send orders to the order gateway
- Track fill confirmations and simulate PnL

### 🔧 Concepts:

- Event-driven logic
- Latency measurement (e.g. time from tick to order)
- Market making / arbitrage basics

---

## 📅 Phase 6: Exchange Simulator (Week 11–12)

### 🔹 Objectives:

- Simulate a matching engine
- Respond to orders and generate fills

### ✅ Tasks:

- Match BUY and SELL orders using FIFO or price-time priority
- Respond with “FILL” messages to clients
- Add latency simulation (e.g. sleep 100µs before sending response)

---

## 📅 Phase 7: Latency Tracking & Benchmarking (Week 13+)

### 🔹 Objectives:

- Measure time from market event → order → fill
- Optimize for lower latency

### ✅ Tasks:

- Add timers using `std::chrono` or CPU cycles (`rdtscp`)
- Log latency per step
- Profile CPU/memory usage with `perf` or valgrind (Linux)
- Consider pinning threads to cores (advanced)

---

## 🧪 Optional Stretch Goals

- Multi-symbol support
- Risk checks (e.g., max open orders)
- GUI dashboard with prices + fills (using web tech)

---

## 🗂 Folder Suggestions

```
/market_data/
  feed_simulator.cpp
  feed_handler.cpp
/order_book/
  order_book.cpp
  order_book_test.cpp
/strategy/
  strategy.cpp
/exchange/
  exchange_simulator.cpp
/network/
  tcp_server.cpp
  udp_server.cpp
/utils/
  timer.cpp
  logger.cpp

```

---

## 🧘 Tips for You

- Start by replacing concepts with ones you're familiar with:
  - Instead of HTTP servers, think: raw TCP/UDP
  - Instead of REST handlers, think: parsing byte streams
  - Instead of databases, think: in-memory maps/vectors
- Build modules like microservices — connected, but independently testable
- Use unit tests for modules like the order book or strategy
