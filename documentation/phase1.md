# Raw networking (TCP/UDP Server)

Learn low-level TCP/UDP socket programming using C++ and POSIX APIs. Build basic servers that simulate market data flow and order entry, forming the foundation for later components.

## 🛠️ **Environment Setup**

- [ ] Install Ubuntu (native or VM)
- [ ] Install development tools:

  - `clang++` or `g++`
  - `cmake`
  - `make`
  - `valgrind`, `perf`, `htop` (optional, for profiling later)

- [ ] Set up a basic C++ build system using CMake
- [ ] Set up Git for version control

---

## 🌐 **TCP Server (Order Gateway Prototype)**

Build a basic TCP server that:

- [ ] Binds to a configurable port (e.g. 9000)
- [ ] Accepts multiple simultaneous client connections
- [ ] Reads incoming messages (e.g. plain text strings like `BUY AAPL 100.50 10\n`)
- [ ] Sends simple acknowledgments back (e.g. `ACK\n`)
- [ ] Logs received messages to `stdout`
- [ ] Uses `select()` (or `poll()`) for handling multiple connections non-blocking
- [ ] Gracefully handles client disconnects and malformed input

**Constraints:**

- Use only C++ standard libraries and POSIX system calls (no Boost or high-level frameworks)
- Do not use `fork()` or a thread-per-connection model

---

## 📡 **UDP Server (Market Data Listener Prototype)**

Build a basic UDP server that:

- [ ] Binds to a configurable port (e.g. 9100)
- [ ] Listens for messages from any sender
- [ ] Parses plain text market data (e.g. `AAPL 100.51\n`)
- [ ] Prints messages to `stdout` in real-time
- [ ] Handles packet drops and out-of-order delivery gracefully (log if needed)

---

## 📚 **Networking Concepts to Learn**

- [ ] Difference between TCP and UDP (reliability, ordering, connection)
- [ ] How to use `socket()`, `bind()`, `listen()`, `accept()`, `recv()`, `send()`, `recvfrom()`
- [ ] Use of `select()` vs `poll()` for multiplexing
- [ ] Blocking vs non-blocking I/O (using `fcntl()` or `setsockopt()`)
- [ ] File descriptor lifecycle and limits

---

## 📁 **Suggested File Structure**

```
/network/
  tcp_server.cpp       // Implements the TCP gateway server
  udp_server.cpp       // Implements the UDP market data receiver
  network_utils.hpp    // Common helpers (e.g., socket setup, logging)
/build/
  CMakeLists.txt       // Build config
```

---

## 🧪 **Completion Criteria**

You’re done with Phase 1 when:

- ✅ You can run a UDP feed simulator (can be `netcat` or another script) and your server logs messages
- ✅ You can connect to your TCP server with `telnet` or a basic client and send orders
- ✅ Your server logs each message and sends back ACKs
- ✅ You understand how `select()` or `poll()` works and how to use them for connection handling
