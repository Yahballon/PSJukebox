<div align="center">

<img src="assets/neon-icon.webp" alt="PSJukebox neon logo" width="164" />

# PSJUKE BOX

**YOUR MUSIC · YOUR CONSOLE**

Native PlayStation 5 Homebrew Music Player · **by YAHBALLON**

[![Release](https://img.shields.io/github/v/release/Yahballon/PSJukebox?style=for-the-badge&label=PSJukebox&color=e8bc38)](https://github.com/Yahballon/PSJukebox/releases)
[![Build](https://img.shields.io/github/actions/workflow/status/Yahballon/PSJukebox/build-psjukebox.yml?branch=main&style=for-the-badge&label=PS5%20Build)](https://github.com/Yahballon/PSJukebox/actions)
[![License](https://img.shields.io/badge/license-GPLv3-2db884?style=for-the-badge)](LICENSE)

**[Download](https://github.com/Yahballon/PSJukebox/releases/latest)** · **[Builds](https://github.com/Yahballon/PSJukebox/actions)** · **[Native source](native/)** · **[Report an issue](https://github.com/Yahballon/PSJukebox/issues)**

</div>

---

## 🎶 A jukebox for your PS5

Bring your own music library to your homebrew-enabled PS5. Explore artists and albums through a beautiful **five-cover 3D coverflow**, watch the illuminated vinyl spin inside **Now Playing**, and play your collection using the DualSense controller.

The native emerald-glass interface features rich album artwork, gold highlights, reflective covers, real playback information, playlists/queue browsing and favorites. No browser required.

### 💚 💛 ❤️ New in v0.1.24 — Every album has its own Rasta colors

Instead of one identical theme everywhere, each album receives a **unique-looking combination of vivid green, gold, and red**. The interface changes the accent, background tint, Rasta stripe order, vinyl detail and decorative spectrum to match that album's colorway.

These variations are based on the album's stable identity, **not a new random draw every frame**. Colors won't flicker when browsing, and the same album retains the same look after restarting. Original album art is never recolored.

## ✨ Features

| Feature | Description |
|---|---|
| 🎴 **3D Coverflow** | Five album jackets, smooth transitions, glowing selection, reflections, cached artwork |
| 💿 **Spinning Vinyl** | Animated at 33⅓ RPM while music plays; freezes instantly on pause |
| 🎵 **Native Audio** | FFmpeg/SDL2 playback of supported MP3, FLAC, M4A/AAC, WAV, OGG, Opus and WMA files |
| 📊 **Audio Details** | Decoder-reported audio format, channels and sample rate |
| 🌐 **Network Music** | SMB2/SMB3 share support with editable in-app settings |
| 💽 **Local / USB** | Scan locally accessible storage and mounted USB directories |
| 💚 **Favorites** | Favorite tracks and navigate songs across album boundaries |
| 🚀 **Fast Artwork** | Background library scan, cached covers and prefetching of nearby jackets |
| 🌍 **Unicode Fonts** | Non-English artist and track names with font fallback |
| 🎨 **Album Themes** | Stable random-looking Rasta palettes per album; optional custom backgrounds and covers |

## 📥 Installation

1. Download the current **[release ZIP](https://github.com/Yahballon/PSJukebox/releases/latest)** (asset: `PPSA99947.zip`).
2. Extract the archive and install/copy the included `PPSA99947` app folder with your PS5 homebrew installation method.
3. Launch PSJukebox on your compatible jailbroken/homebrew-enabled PS5.
4. Add your music locally, over USB, or configure an SMB share in **Settings**. Let the library scan finish.

**Title ID:** `PPSA99947` · **Current version:** `v0.1.24` · **Developer:** `YAHBALLON`

### Music folders

The app scans these directories when they are accessible:

```text
/data/PSJukebox/Music
/download0/PSJukebox/Music
/mnt/usb0/PSJukebox/Music
/mnt/usb1/PSJukebox/Music
/mnt/usb0/Music
/mnt/usb1/Music
```

Organize content by artist and album:

```text
Music/
└── Example Artist/
    ├── background.jpg         # optional artist background
    ├── logo.png               # optional logo
    ├── First Album/
    │   ├── cover.jpg
    │   ├── 01 - First Song.flac
    │   └── 02 - Another Song.mp3
    └── Second Album/
        ├── cover.png
        └── 01 - Favorite Song.mp3
```

Only include media and images you have the rights to use. The repository does **not** distribute commercial music or game files.

## 🌐 SMB network shares

Open **OPTIONS → Settings → SMB Network Share** to configure Server/IP, share, optional subfolder, username, password and domain. Save with **SAVE & RESCAN**. Alternatively, use `/data/PSJukebox/smb.ini`:

```ini
server=192.168.1.10
share=Music
path=
username=Guest
password=
domain=
```

Your credentials stay in a local file on the console; passwords are masked in the UI but the file itself is not encrypted. Use a separate least-privilege SMB account, ideally read-only.

## 🎮 DualSense controls

| Button | Action |
|---|---|
| **D-pad ← / →** | Previous / next album |
| **L1 / R1** | Previous / next artist |
| **L2 / R2** | Previous / next song |
| **X** | Select / play / open selected album tracks |
| **Square** | Pause / resume |
| **Triangle** | Toggle favorite |
| **OPTIONS** | Open settings |
| **Circle** | Back |
| **Horizontal analog input** | Seek in supported playback views |

The footer automatically shows the controls relevant to the active view.

## 🛠️ Build & release

The independent **[Build PSJukebox workflow](.github/workflows/build-psjukebox.yml)** automatically builds on changes to `main` and can also be started manually under **Actions → Build PSJukebox → Run workflow**.

It runs host regression tests (including the vinyl-motor and Rasta-colorway tests), prepares unicode fonts, fetches the homebrew SDK and open-source audio dependencies, compiles the native PS5 ELF, verifies the install layout and publishes `PPSA99947.zip` as a versioned release.

### Repository layout

```text
native/                 C++ app, coverflow, audio, UI and SMB
tests/                  Host regression tests
helper/                 Console-side scanner helper
tools/                  Assets, build preparation and validation
assets/                 Neon application icon
.github/workflows/      PS5 native CI and release automation
app.json                Version, title ID and build metadata
RELEASE_NOTES.md        Current version changes
LICENSE                 GPL-3.0
```

Logs: `/data/PSJukebox/psjukebox.log`. Persistent config and library cache live under `/data/PSJukebox/`.

## 🤝 Credits

**PSJukebox by YAHBALLON**. Built with open-source PS5 homebrew tooling and FFmpeg/SDL2. This independent project is not affiliated with Sony or PlayStation.

Licensed under **[GNU GPL v3](LICENSE)**.

<div align="center">

**Your music. Your console. 💚💛❤️**

</div>
