#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

#this is CMakeLists.txt for lock_unittests
cmake_minimum_required(VERSION 2.8.11)

compileAsC11()
set(theseTestsName mqtt_client_unittests)

set(${theseTestsName}_test_files
${theseTestsName}.c
)

set(${theseTestsName}_c_files
../../src/mqtt_client.c
)

set(${theseTestsName}_h_files
)

include_directories(${MQTT_SRC_FOLDER})

build_c_test_artifacts(${theseTestsName} ON "umqtt_tests")
