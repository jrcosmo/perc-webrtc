/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "modules/rtp_rtcp/source/rtp_receiver_strategy.h"
#include "rtc_base/logging.h"

#include <stdlib.h>

namespace webrtc {

RTPReceiverStrategy::RTPReceiverStrategy(RtpData* data_callback)
    : data_callback_(data_callback) {}

RTPReceiverStrategy::~RTPReceiverStrategy() = default;

void RTPReceiverStrategy::CheckPayloadChanged(int8_t payload_type,
                                              PayloadUnion* specific_payload,
                                              bool* should_discard_changes) {
  // Default: Keep changes.
  *should_discard_changes = false;
}

bool RTPReceiverStrategy::SetMediaCrypto(
    const std::shared_ptr<webrtc::MediaCrypto>& media_crypto) {
  RTC_LOG(LS_INFO) << "Setting End to End Media Encryption";
  rtc::CritScope cs(&crit_sect_);
  media_crypto_ = media_crypto;
  return true;
}

}  // namespace webrtc
