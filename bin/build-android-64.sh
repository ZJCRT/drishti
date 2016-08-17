#!/bin/bash

. ${DRISHTISDK}/bin/build-common.sh

TOOLCHAIN=android-ndk-r10e-api-21-arm64-v8a-gcc-49-hid

EXTRA_ARGS=""
if [ $# -ge 1 ]; then
    EXTRA_ARGS="--clear"
fi

rename_tab drishti $TOOLCHAIN

COMMAND=(
    "--verbose --fwd ANDROID=TRUE "
    "${DRISHTI_BUILD_ARGS[*]} "
    "${DRISHTI_BUILD_HIDE[*]} "
    "ANDROID_COMPILER_VERSION=\"4.9\" "
    "--config Release "
    "--pack ${CPACK_TYPE} "
    "--jobs 8 "
    "--strip "
    "${EXTRA_ARGS} "
)

eval build.py --toolchain ${TOOLCHAIN} ${COMMAND[*]}

echo "Finished with status $?" 




