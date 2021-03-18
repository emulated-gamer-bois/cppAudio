# cppAudio

A small repo for checkoing out [openal-soft](https://github.com/kcat/openal-soft) which will be integrated with gameboy-emulator

The OpenAL programmer guide can be found [here](https://www.openal.org/documentation/OpenAL_Programmers_Guide.pdf)

# Setup

```
    git clone git@github.com:emulated-gamer-bois/cppAudio.git
    cd cppAudio
    git submodule update --init --recursive
```

Open the project in CLion and you should be able of building and running it

## Known Issues

- cmake throws errors on Windows since the `CMakeList.txt` is badly written
- Error message:

```
[ALSOFT] (EE) Failed to set real-time priority for thread: Operation not permitted (1)
```

Fix this by inserting the following in the `/etc/security/limits.conf` file and then reboot:

```
<your user name> hard rtprio 1
```

For more information, look [here](https://linuxhint.com/permanently_set_ulimit_value/)
