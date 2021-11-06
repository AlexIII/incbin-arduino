# incbin - Include binary and text files in your Arduino project with ease

*This is a fork of [this](https://github.com/graphitemaster/incbin) project wrapped as an Arduino library.*

The library allows to include any file into your Arduino project in a single line without 
converting it into c-array or maintaining a file system (such as SPIFFS).

Easily include wav sound, bmp image, html, js, txt, etc.

## IMPORTANT NOTE

When using this library,
  1. Close **all** Arduino IDE windows,
  2. Re-open your ***.ino file via double-click**. Do NOT do File -> Open...

See [Limitations](#Limitations) for the explanation.


## How to use

```C++
#include "incbin.h"

INCTEXT(WebPage, "index.html");         // For text     (will be NULL-terminated)
INCBIN(Sound, "sound.wav");             // For binary   (will STILL be NULL-terminated)

void setup() {
  Serial.begin(115200);

  Serial.println(gWebPageData);         // print content of index.html
  Serial.println();

  Serial.print(F("index.html size: "));
  Serial.println(gWebPageSize);         // print size of index.html

  Serial.print(F("sound.wav size: "));
  Serial.println(gSoundSize);           // print size of sound.wav
}
```

Macros `INCTEXT(NAME, FILE)` and `INCBIN(NAME, FILE)` accept path to the `FILE` 
**relative to the project main folder** (where the *.ino file is placed), and 
NOT to the source file in which you use these macros. You can use absolute path as well.

See the [`incbin-print-self.ino`](examples/incbin-print-self/incbin-print-self.ino) example for more. 


## How it works

The library includes the content of the specified file in Flash ROM of the microcontroller.
It means that,

- the RAM is not wasted;
- the file is included as a constant, its content cannot be changed;
- you cannot work with the file content as with a normal array on AVR-based Arduino, as it's stored in the flash memory (PROGMEM). See [here](https://www.arduino.cc/reference/en/language/variables/utilities/progmem/) on how to read the flash.


## Limitations

If you encounter a compilation error like this

```
***PATH***.s: Assembler messages:
***PATH***.s:16: Error: file not found: ***FILE YOU TRIED TO INCBIN***
lto-wrapper.exe: fatal error: 
    ...
```

do the following steps:

#### Windows Arduino IDE 1.8 users
  1. Close **all** Arduino IDE windows,
  2. Re-open your ***.ino file via double-click**. Do NOT do File -> Open...

#### VS Code Arduino extension users (any OS)
  1. Upgrade your extension to v0.4.7 or newer,
  2. Ensure the path in the INCBIN or INCTEXT is **relative to the workspace folder**, and not to the source file. You can also use absolute path.

#### Windows Arduino IDE 2 Beta, Linux Arduino IDE (any)
No solutions to use relative path. Sorry. Use absolute path instead. Linux users may also use path relative to home.

### Ok, but why???

The underlying library uses the `.incbin` directive of the inline assembler. The thing is, it accepts the path relative to the current directory in which the compiler is running (and not to the source file).
Arduino IDE *usually* starts the build in the project main directory (in which the *.ino file resides), but it is not guaranteed. Sometimes build can start in another directory and will fail. Re-opening the IDE via double-click on the *.ino file convinces it to start the build in the project's folder (but only in ver. 1.8 under Windows).

Also, a library example never runs compilation in its own folder, that's why you need to copy it somewhere on the disk, otherwise the compilation will fail.

**If you have an idea on how to handle this *right* way, please post an issue on the subject.**


## Supported architectures

Tested with
- AVR-based Arduino: Uno, Nano, Mini Pro, 2560, etc.
- ESP8266

Should also work with
- ARM-based Arduino


## License

MIT 

© [Dale Weiler](https://github.com/graphitemaster)

© [AlexIII](https://github.com/AlexIII)


The original library goes under [UNLICENSE](src/UNLICENSE).
I'm no legal expert, but I think it permits derivative work to have a different license.
If you think it's not, then please post an issue.
