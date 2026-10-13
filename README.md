# noit
> *The world's most deterministic init system.*
```
welcome to noit! Itll be a long wait. Waiting...
```
---
## What is `noit`?
`noit` (pronounced *no-it*, or simply the sound of giving up) is an ultra-minimal, high-efficiency, zero-dependency PID 1 for the Linux operating system.
While modern init systems burden your CPU with complex dependency graphs, DBus protocols, socket activation, dynamic service supervisors, and multi-gigabyte journal logs, `noit` solves the problem at its root:
**If no services ever start, no services can ever crash.**
---
## Features
- **Blazing Fast Boot Time:** Reaches peak uptime readiness in ~0.000004 seconds.
- **0.0% CPU Utilization:** Powered by pure POSIX `pause()`. It does not busy-wait. It simply dreams.
- **Zero Configuration:** No `/etc/inittab`, no YAML, no `.service` files, no XML manifests, no runlevels. It doesn't care who you are or what you want.
- **Immune to CVEs:** You cannot exploit a daemon that was never executed.
- **Rock-Solid Stability:** 100% uptime guaranteed until the heat death of the universe or your laptop battery dies (whichever comes first).
- **Infinite Patience:** It will wait. Forever.
---
## Architecture Diagram
```
 [ Linux Kernel ]
        │
        ▼
   ( PID 1 )
       noit
        │
        ├──► printf("welcome to noit! Itll be a long wait. Waiting...\n");
        │
        └──► for (;;) { pause(); }
```
---
## Comparison Table

| Feature | systemd | OpenRC | runit | `noit` |
| :--- | :--- | :--- | :--- | :--- |
| **Lines of Code** | ~1.3M | ~30k | ~5k | **11** |
| **Socket Activation** | Yes | No | No | **No.** |
| **Reaps Zombies** | Yes | Yes | Yes | **The zombies live here now.** |
| **Can Break DNS** | Frequently | Rarely | Never | **Physically incapable** |
| **Spawns Login Shell** | Yes | Yes | Yes | **Why would you need in?** |

---
## Installation
### 1. Compile
```bash
gcc -static -O3 noit.c -o noit
strip -s noit
```
### 2. Install to Bare Metal
```bash
# WARNING: Do not actually do this unless you enjoy holding down power buttons
sudo cp noit /sbin/noit
```
Add to your GRUB / kernel command line:
```
init=/sbin/noit
```
### 3. Test Safely in QEMU
```bash
qemu-system-x86_64 \
  -kernel /boot/vmlinuz-linux \
  -append "console=ttyS0 init=/noit" \
  -initrd ./initramfs.cpio.gz \
  -nographic
```
---
## FAQ
**Q: My screen is frozen after the message. Is it working?**  
A: Yes. It is waiting.
**Q: How do I shut down cleanly?**  
A: Pull the plug from the wall. Or wait for the battery to die. `noit` does not acknowledge `SIGTERM`, `SIGINT`, or your panic.
**Q: Can I run Docker / Podman containers under `noit`?**  
A: Absolutely not.
**Q: Is this POSIX compliant?**  
A: The `for (;;)` loop is standardized across all known realities.
---
## License
No License.
Just like the code does nothing, the legal terms do nothing. It is 11 lines of pure C. Do whatever you want, or do nothing at all—`noit` will still be waiting.
