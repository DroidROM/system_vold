/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_VOLD_TRIM_TASK_H
#define ANDROID_VOLD_TRIM_TASK_H

#include "android/os/IVoldTaskListener.h"
#include "Utils.h"

#include <thread>
#include <list>

namespace android {
namespace vold {

class TrimTask {
public:
    explicit TrimTask(int flags, const android::sp<android::os::IVoldTaskListener>& listener);
    virtual ~TrimTask();

    enum Flags {
        kDeepTrim = 1 << 0,
    };

    void start();

private:
    int mFlags;
    android::sp<android::os::IVoldTaskListener> mListener;
    std::list<std::string> mPaths;
    std::thread mThread;

    void addFromFstab();
    void run();

    DISALLOW_COPY_AND_ASSIGN(TrimTask);
};

}  // namespace vold
}  // namespace android

#endif
