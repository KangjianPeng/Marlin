# Firmware Build and Release

This repository builds the Qingwa PnP firmware for the Opulo Lumen REV5 board
(`Opulo_Lumen_REV5`) with PlatformIO.

Pushes to `dev-rev5-upstream` and pull requests targeting that branch build the
firmware and upload the binary, build metadata, SHA-256 checksum, and ZIP package
as a workflow artifact.

Push a version tag such as `v1.0.0` to build the firmware and publish a GitHub
Release containing the same files:

```sh
git tag v1.0.0
git push kangjian v1.0.0
```

The firmware binary is produced at `.pio/build/Opulo_Lumen_REV5/firmware.bin`.
