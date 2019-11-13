/*
 * Copyright 2019 The Android Open Source Project
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
#ifndef _IO_WAV_WAVSTREAMREADER_H_
#define _IO_WAV_WAVSTREAMREADER_H_

#include <map>

#include "AudioFormat.h"
#include "WavRIFFChunkHeader.h"
#include "WavFmtChunkHeader.h"

namespace wavlib {

class InputStream;

class WavStreamReader {
public:
    WavStreamReader(InputStream *stream);

    int getSampleRate() { return mFmtChunk->mSampleRate; }

    int getNumSampleFrames() {
        return mDataChunk->mChunkSize / (mFmtChunk->mSampleSize / 8) / mFmtChunk->mNumChannels;
    }

    int getNumChannels() { return mFmtChunk != 0 ? mFmtChunk->mNumChannels : 0; }

    int getSampleFormat();

    int getBitsPerSample() { return mFmtChunk->mSampleSize; }

    void parse();

    // Data access
    void positionToAudio();

    int getData(float *buff, int numFrames);

protected:
    InputStream *mStream;

    WavRIFFChunkHeader *mWavChunk;
    WavFmtChunkHeader *mFmtChunk;
    WavChunkHeader *mDataChunk;

    long mAudioDataStartPos;

    std::map<RiffID, WavChunkHeader *> *mChunkMap;
};

} // namespace wavlib

#endif // _IO_WAV_WAVSTREAMREADER_H_
