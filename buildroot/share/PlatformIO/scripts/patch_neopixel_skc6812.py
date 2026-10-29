import pioutil

if pioutil.is_pio_build() and pioutil.env["PIOENV"] == "Opulo_Lumen_REV5":
    from pathlib import Path

    env = pioutil.env
    libdeps_dir = Path(env.subst("$PROJECT_LIBDEPS_DIR"))
    if not libdeps_dir.is_absolute():
        libdeps_dir = Path.cwd() / libdeps_dir

    sources = list(libdeps_dir.glob("**/Adafruit_NeoPixel.cpp"))
    if len(sources) != 1:
        raise RuntimeError(
            "Expected one Adafruit_NeoPixel.cpp in PlatformIO dependencies, "
            f"found {len(sources)} under {libdeps_dir}"
        )

    source_path = sources[0]
    source = source_path.read_bytes()
    newline = b"\r\n" if b"\r\n" in source else b"\n"
    old = newline.join((
        b"    uint32_t top = (F_CPU / 800000);       // 1.25\xc2\xb5s",
        b"    uint32_t t0 = top - (F_CPU / 2500000); // 0.4\xc2\xb5s",
        b"    uint32_t t1 = top - (F_CPU / 1250000); // 0.8\xc2\xb5s",
    )) + newline
    new = newline.join((
        b"    uint32_t top = (F_CPU / 800000);       // 1.25\xc2\xb5s",
        b"    uint32_t t0 = top - (F_CPU / 3333333); // 0.3\xc2\xb5s high for a 0 bit",
        b"    uint32_t t1 = top - (F_CPU / 1111111); // 0.9\xc2\xb5s high for a 1 bit",
    )) + newline

    if new in source:
        pass
    elif old in source:
        source_path.write_bytes(source.replace(old, new, 1))
        print(f"Applied SKC6812RGBW-NW timing patch to {source_path}")
    else:
        raise RuntimeError(
            "Adafruit NeoPixel STM32 timing block did not match the expected "
            "1.12.x source; refusing to build with unverified timing"
        )
