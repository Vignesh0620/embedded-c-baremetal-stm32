# Cortex-M Fundamentals

The **ARM Cortex-M** series is a family of ARM microprocessor cores designed for embedded systems. It is widely used in microcontrollers due to its low power consumption, high efficiency, and ease of use.

---

## 📚 Overview of Cortex-M Series

| Series     | Key Use Case               | Performance      | Notes                        |
|------------|----------------------------|------------------|------------------------------|
| Cortex-M0  | Ultra-low power            | Basic            | Minimal footprint            |
| Cortex-M0+ | Improved M0                | Very efficient   | Smallest silicon area        |
| Cortex-M3  | General-purpose            | Medium           | Rich set of features         |
| Cortex-M4  | DSP + FPU                  | Medium-high      | Ideal for audio/controls     |
| Cortex-M7  | High performance + DSP/FPU | High             | Advanced automotive/IoT      |
| Cortex-M23 | Security (TrustZone)       | Low              | M0-class + security          |
| Cortex-M33 | Security + performance     | Medium           | M3-class + TrustZone         |


- **Harvard architecture:** Separate instruction and data buses
- **Thumb-2 instruction set:** 16-bit and 32-bit mixed instructions
- **Low interrupt latency:** NVIC (Nested Vectored Interrupt Controller)
- **SysTick Timer:** Built-in 24-bit timer for RTOS tick or delay
- **Bit-banding:** Fast bit-level manipulation (Cortex-M3 and above)
- **Integrated Debugging:** SWD, DWT, ITM, ETM support
- **Optional FPU and DSP:** In Cortex-M4 and M7

Follow the below Link for In-depth Details & Learning
https://www.ti.com/lit/ml/swrp141/swrp141.pdf?ts=1754390973947&ref_url=https%253A%252F%252Fin.search.yahoo.com%252F

#Suggestion

https://mu.microchip.com/arm-cortex-m-architecture-overview 

Register and Learn from this course if you have time