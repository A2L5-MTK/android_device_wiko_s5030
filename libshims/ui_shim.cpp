#include <gui/BufferItem.h>
#include <gui/IConsumerListener.h>
#include <gui/IGraphicBufferConsumer.h>
#include <ui/GraphicBufferMapper.h>
#include <gui/BufferItemConsumer.h>
#include <ui/Rect.h>

#include <log/log.h>
#define LOG_TAG "BufferQueue_shim"

extern "C" {
    void _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv(buffer_handle_t, uint32_t, const android::Rect&, void**);

    void _ZN7android19GraphicBufferMapper4lockEPK13native_handleiRKNS_4RectEPPv(buffer_handle_t handle, int usage, const android::Rect& bounds, void** vaddr) {
        _ZN7android19GraphicBufferMapper4lockEPK13native_handlejRKNS_4RectEPPv(handle, static_cast<uint32_t>(usage), bounds, vaddr);
    }
}

extern "C" {
    void _ZN7android19GraphicBufferMapper9lockYCbCrEPK13native_handlejRKNS_4RectEP13android_ycbcr(buffer_handle_t, uint32_t, const android::Rect&, android_ycbcr*);
    void _ZN7android19GraphicBufferMapper9lockYCbCrEPK13native_handleiRKNS_4RectEP13android_ycbcr(buffer_handle_t, int, const android::Rect&, android_ycbcr*);

    void _ZN7android19GraphicBufferMapper9lockYCbCrEPK13native_handleiRKNS_4RectEP13android_ycbcr(buffer_handle_t handle, int usage, const android::Rect& bounds, android_ycbcr *ycbcr) {
        _ZN7android19GraphicBufferMapper9lockYCbCrEPK13native_handlejRKNS_4RectEP13android_ycbcr(handle, static_cast<uint32_t>(usage), bounds, ycbcr);
    }
}

extern "C" void _ZN7android22IGraphicBufferConsumerC2Ev();

// The constructor was replaced in Android 6.0
extern "C" void _ZN7android22IGraphicBufferConsumer10BufferItemC1Ev() {
    return _ZN7android22IGraphicBufferConsumerC2Ev();
}

namespace android {

// The function was removed in Android 6.0
extern "C" status_t _ZN7android18BufferItemConsumer20setDefaultBufferSizeEjj(uint32_t w, uint32_t h) {
    ALOGD("%s: deprecated call. w -> %lu, h -> %lu", __func__, w, h);
    return 0;
}

// The function was removed in Android 6.0
extern "C" status_t _ZN7android18BufferItemConsumer22setDefaultBufferFormatEj(uint32_t defaultformat) {
    ALOGD("%s: deprecated call. defaultformat -> %lu", __func__, defaultformat);
    return 0;
}

extern "C" status_t _ZN7android18BufferItemConsumer13acquireBufferEPNS_10BufferItemExb(BufferItem *item,
        nsecs_t presentWhen, bool waitForFence);

// The function was renamed in Android 6.0
extern "C" status_t _ZN7android18BufferItemConsumer13acquireBufferEPNS_22IGraphicBufferConsumer10BufferItemExb(BufferItem *item,
    nsecs_t presentWhen, bool waitForFence) {
        return _ZN7android18BufferItemConsumer13acquireBufferEPNS_10BufferItemExb(item, presentWhen, waitForFence);
}

extern "C" status_t _ZN7android18BufferItemConsumer13releaseBufferERKNS_10BufferItemERKNS_2spINS_5FenceEEE(const BufferItem &item,
    const sp<Fence>& releaseFence);

// The function was renamed in Android 6.0
extern "C" status_t _ZN7android18BufferItemConsumer13releaseBufferERKNS_22IGraphicBufferConsumer10BufferItemERKNS_2spINS_5FenceEEE(const BufferItem &item,
    const sp<Fence>& releaseFence) {
        return _ZN7android18BufferItemConsumer13releaseBufferERKNS_10BufferItemERKNS_2spINS_5FenceEEE(item, releaseFence);
}

} // namespace android
