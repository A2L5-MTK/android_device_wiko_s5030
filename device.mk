#
# Copyright (C) 2021 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

## Device Path
DEVICE_PATH := device/wiko/s5030

## Vendor Blobs
$(call inherit-product, vendor/wiko/s5030/s5030-vendor.mk)

# Display
TARGET_SCREEN_HEIGHT := 854
TARGET_SCREEN_WIDTH := 480

# Rootdir
PRODUCT_PACKAGES += \
    enableswap.sh \
    fstab.mt6580 \
    init.modem.rc \
    init.mt6580.rc \
    init.mt6580.usb.rc \
    init.nvdata.rc \
    init.project.rc \
    ueventd.mt6580.rc
