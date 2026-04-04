# 🌍 Posttest 1 Praktikum IoT - UNMUL 2026

Repositori ini berisi *source code* dan dokumentasi untuk pemenuhan Tugas Posttest 1 Praktikum Internet of Things (IoT). Proyek ini berfokus pada pembuatan sistem monitoring level gas dan kontrol aktuator (LED) melalui konektivitas Wi-Fi dan platform IoT.

---

## 👥 Anggota Kelompok

| Nama Lengkap | NIM |
| :--- | :--- |
| [Rifqi Ramadhan] | [2309106007] |
| [Irvan Nurdiansyah] | [23091084] |
| [Achmad Zidan Al-Baihaqi] | [2309106070] |

---

## 📖 Judul Studi Kasus
**Sistem Monitoring Level Gas dan Kontrol LED Cerdas Berbasis Platform IoT**

---

## 📝 Deskripsi
Proyek ini adalah prototipe sistem keamanan dan pemantauan lingkungan berbasis Internet of Things (IoT) menggunakan mikrokontroler [Sebutkan board yang dipakai, misal: ESP32 / NodeMCU ESP8266]. Sistem membaca kadar gas di sekitar menggunakan sensor MQ dan memberikan respons visual melalui 3 buah LED dengan logika sebagai berikut:

- **Indikator Bahaya (Otomatis):**
  - Level Gas `0 - 200`: **LED 1** berkedip selama 3 detik.
  - Level Gas `201 - 500`: **LED 2** berkedip selama 5 detik.
  - Level Gas `> 500`: **LED 3** berkedip selama 7 detik.
- **Mode Aman (Kontrol Manual):**
  - Jika gas tidak terdeteksi (berada pada batas aman), maka LED 1, LED 2, dan LED 3 dapat dikontrol secara manual (On/Off) dari jarak jauh melalui platform IoT [Sebutkan platformnya, misal: Thinger.io / Blynk].

Sistem ini memastikan perangkat terhubung secara *real-time* ke jaringan Wi-Fi untuk memantau nilai sensor dan mengendalikan komponen dari platform IoT.

---

## ⚙️ Komponen yang Digunakan

1. 1x Board Mikrokontroler ([ESP32 / NodeMCU ESP8266])
2. 1x Sensor Gas (MQ Series, misal: MQ-2 / MQ-135)
3. 3x LED (Hijau, Kuning, Merah)
5. Kabel Jumper (Male-to-Male secukupnya)
6. 2x Breadboard
7. Koneksi Wi-Fi dan Platform IoT ([Blynk])

---

## 🛠️ Pembagian Tugas

| Nama Anggota | Deskripsi Tugas / Peran |
| :--- | :--- |
| **[Rifqi Ramadhan]** | Menyusun rangkaian *hardware* pada breadboard dan membuat *Board Schematic*. |
| **[Irvan Nurdiansyah]** | Menyusun laporan/dokumentasi (README) dan melakukan *testing* fungsionalitas. |
| **[Achmad Zidan Al-Baihaqi]** | Menulis *source code* (.ino), mengatur koneksi Wi-Fi, dan konfigurasi platform IoT. |

---

## 🔌 Board Schematic

![Board Schematic](![WhatsApp Image 2026-04-04 at 11 28 29](https://github.com/user-attachments/assets/81a49173-5078-4c78-adb4-fcf1a1e3c4d4)
)


---

## 🎥 Video Demo

Berikut adalah video demonstrasi dari proyek kami yang memperlihatkan anggota kelompok, rangkaian *hardware*, *source code*, dan hasil monitoring/kontrol pada platform IoT:

[![Video Demo](https://img.shields.io/badge/YouTube-Tonton_Video_Demo-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://youtu.be/Z9vJUIW4ca0?si=3dsvL6wt-LrT72V8)
