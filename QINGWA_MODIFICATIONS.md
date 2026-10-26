# 青蛙贴片机固件修改记录

本目录是基于 Marlin 2.1.x 和 Opulo LumenPnP REV5（STM32F407VET6）的青蛙贴片机固件。
默认 PlatformIO 构建目标为 `Opulo_Lumen_REV5`。

## 当前固件修改

### `Marlin/Configuration.h`

- 目标板设为 `BOARD_OPULO_LUMEN_REV5`，主串口使用 USB CDC（`SERIAL_PORT -1`，250000 baud）。
- X/Y/Y2/Z/I/J 六路驱动统一设为 TMC2209，关闭挤出机（`EXTRUDERS 0`）和全部温度传感器。
- 启用贴片机运动参数、限位和 RS485 相关配置，保留 LumenPnP 的多轴运动控制路径。

- X/Y 最大进给速度从 `1500` 调整为 `7000`。
- X/Y 最大加速度从 `10000` 调整为 `15000`。
- Z 归零后的抬升高度从 `31.5` 调整为 `21`。
- LCD 语言设为简体中文（`zh_CN`）。
- 启用蜂鸣器。
- 两组 NeoPixel 灯带长度从 8 灯调整为 18 灯。

### `Marlin/Configuration_adv.h`

- 启用控制板风扇，使用 `PE2`，电机停止后的保持时间设为 120 秒。
- 设置开机提示音序列（多段 `M300` 与 `G4` 指令）。

### `platformio.ini`

- 默认构建环境设为 `Opulo_Lumen_REV5`。
- 通过 `default_src_filter` 排除显示、SD 卡、温控、3D 打印校准和其他未使用模块，缩小纯运动控制固件的构建范围。

### `Marlin/src/pins/stm32f4/pins_OPULO_LUMEN_REV5.h`

- 保留并使用 LumenPnP REV5 的六轴步进、TMC2209、限位、送料器、RS485、AUX、蜂鸣器、风扇和双 NeoPixel 引脚定义。
- 板卡标识为 `LumenPnP Motherboard REV05`，机器名为 `LumenPnP`。

### `Marlin/src/HAL/STM32/timers.cpp`

- 保留 STM32F4 的步进、温度、TMC 软件串口和蜂鸣器定时器分工，并在编译期检查定时器冲突。
- 使用当前 Marlin 宏接口（`IF_ENABLED`、`LOOP_*`）适配该固件所用的 HAL 代码版本。

## 清理内容

- 删除 PlatformIO `.pio` 编译输出。
- 删除 VS Code 自动生成的本机路径配置和 Python `__pycache__`。
- 删除未被构建流程使用的 CMake 临时目录。
- 删除重复的配置压缩包；对应配置目录仍保留在 `Marlin/` 下。

硬件烧录和贴片机现场运行尚未在本机验证；本地验证仅覆盖源码检查和 PlatformIO 编译。
