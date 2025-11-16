# RT EdgeViewer – Real-Time Edge Detection (Android + Web)

This project implements a real-time camera edge detection system using:

- Android (Camera2 + TextureView)
- OpenCV through C++ (NDK + JNI)
- OpenGL ES 2.0 for rendering processed frames
- A basic Web Viewer to display the latest processed frame

---

## ✅ Features Implemented (Android + Web)

### 📱 Android
- Camera2 live preview
- Extract RGBA frames from TextureView
- JNI bridge for native processing
- Canny Edge Detection using OpenCV (C++)
- GLSurfaceView + OpenGL texture rendering
- Saving processed frames to Android gallery

### 🌐 Web
- Simple HTML viewer
- Auto-refreshing the latest processed frame

---





---

## ⚙ Setup Instructions (Android)

### 1️⃣ Install Required Tools
Make sure you have:

- **Android Studio / SDK**
- **NDK (Side-by-side)**  
- **CMake**
- **LLDB**
- **Java 17**

You can install them in:


### 2️⃣ Add OpenCV Android SDK
Download OpenCV (latest Android version) from:

https://opencv.org/releases/

Extract and copy: 
into the project:


### 3️⃣ Build the Project
You can build using:


or open in Cursor / Android Studio → **Build**.

### 4️⃣ Permissions Required
Declared in AndroidManifest:

- Camera access
- Storage / Media saving

### 5️⃣ Running the App
1. Connect device  
2. Run the app  
3. You will see:
   - Live camera preview  
   - Processed OpenCV Canny output on top  
   - Frames saved automatically in:
     ```
     Pictures/RT_EdgeViewer/
     ```




