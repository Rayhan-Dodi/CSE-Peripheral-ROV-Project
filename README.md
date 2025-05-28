# 🎮 Joystick-Controlled ROV (Remotely Operated Vehicle)

An academic project created for the **Peripheral Interface** course as part of my Computer Science & Engineering (C.S.E) studies. This ROV prototype was developed purely for fun and learning — to explore real-time hardware control using Arduino and joystick modules.

---

## 🧠 Project Overview

- 🎓 **Type**: University Project  
- 📚 **Subject**: Peripheral Interface  
- 👨‍💻 **Creator**: Rayhan (C.S.E Student)  
- 🔧 **Goal**: Learn practical hardware interfacing and real-time motor control

---

## ⚙️ Hardware Components

- Arduino UNO (Microcontroller)
- L298N Motor Driver
- Dual DC Motors
- Joystick Module
- 12V Battery Supply
- Waterproof Frame (custom-built)

---

## 🎯 Features

- ✅ Real-time movement: Forward, Backward, Turn Left, Turn Right, Stop
- ✅ Responsive Joystick Control
- ✅ No Overheating Detected
- ✅ Stable Movement in Water
- ✅ Clean motor response & logic handling

---

## 🧪 Performance Test

**Testing Environment**:  
- Water Tank Depth: ~40 cm  
- Duration: ~5–10 minutes  
- Power Supply: 12V Battery  

### 💧 Test Results

| Movement     | Response   |
|--------------|------------|
| Forward      | ✅ Instant |
| Backward     | ✅ Instant |
| Turn Left    | ✅ Smooth  |
| Turn Right   | ✅ Smooth  |
| Stop         | ✅ Stable  |

- No heating issues on the L298N module  
- Accurate joystick readings  
- No system lag or signal delays

---

## 📷 Visuals

![ROV Testing](images/rov_water_test.jpg) <!-- Replace with actual image filename -->

---

## 💻 Sample Code Snippet

```cpp
int motorPin1 = 5;
int motorPin2 = 6;

void loop() {
   int joyVal = analogRead(A0);
   if (joyVal > 700) {
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
   }
}
