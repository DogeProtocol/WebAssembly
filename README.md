## Web Assembly
This repository contains WASM (Web Assembly) for the Falcon Post Quantum Cryptography scheme.
The web assembly is generated from [Falcon Repository](https://github.com/DogeProtocol/Falcon).

## Prerequisites

### Falcon C Code
Ensure you have cloned https://github.com/DogeProtocol/Falcon and have a buildable version with no compilation errors.

### Emscripten SDK
Ensure that you have installed the Emscriten SDK, following [instructions](https://emscripten.org/docs/getting_started/downloads.html) at https://emscripten.org/docs/getting_started/downloads.html.
 
## Building

1) Set the Emscripten environment variable if not already set. For example:
```
emsdk_env.bat
```

2) Run the following command. Replace paths accordingly to where they are located in your computer.

```
emcc -s WASM=1 -s EXPORTED_FUNCTIONS="['_free', '_malloc']"  -s "EXPORTED_RUNTIME_METHODS=['getValue']" c:/WebAssembly/Falcon/webp.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/codec.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/common.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/fft.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/fpr.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/keygen.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/nist.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/rng.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/shake.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/sign.c c:/Falcon/Reference_Implementation/falcon512/falcon512int/vrfy.c -o c:/WebAssembly/Falcon/falcon.html
```

## Contributing

Thank you for considering to help out with the source code! 

* Please reach out in [our Discord Server](https://discord.gg/bbbMPyzJTM) for any questions. 
* Pull requests need to be based on and opened against the `main` branch.

## License

This Falcon implementation is provided under the MIT license, whose text
is included at the start of every source file.
