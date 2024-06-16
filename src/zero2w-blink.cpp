/*
 * Copyright (c) 2024 by Bert Laverman. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <cstdint>
#include <iostream>
#include <string>

#include <raspberry-pi.hpp>
#include <components/local-led.hpp>

using namespace nl::rakis::raspberrypi;


int main([[maybe_unused]] int argc, [[maybe_unused]] char*argv[])
{
    RaspberryPi& pi(RaspberryPi::instance());
    pi.gpio().verbose(true);

    std::cerr << "Starting test\n";

    components::LocalLed led(pi, 17);

    int count = (argc > 1) ? atoi(argv[1]) : 10;
    for (int i = 0; i < count; ++i) {
        led.toggle();

        pi.sleepMs(500);
    }
    std::cerr << "Shutting down.\n";
}

