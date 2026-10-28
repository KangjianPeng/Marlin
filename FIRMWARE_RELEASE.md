# Firmware Build and Release

This repository builds the Qingwa PnP firmware for the Opulo Lumen REV5 board
(`Opulo_Lumen_REV5`) with PlatformIO.

## Continuous builds

- Pull requests targeting `dev` and pushes to `dev` build
  the firmware and attach the `.bin`, build metadata, SHA-256 checksum, and ZIP
  package to the GitHub Actions run for 30 days.
- The workflow is `.github/workflows/build-qingwa-firmware.yml`.

## Releases

Push a version tag such as `v1.0.0` to start a build and publish a GitHub
Release. The release includes the `.bin`, `SHA256SUMS`, `BUILD-INFO.txt`, and a
ZIP containing those files. The build must succeed before the release is
published.

```sh
git tag v1.0.0
git push origin v1.0.0
```

The firmware binary is produced at `.pio/build/Opulo_Lumen_REV5/firmware.bin`.
The generated build metadata records the tag or commit and the PlatformIO
environment used for the build.
