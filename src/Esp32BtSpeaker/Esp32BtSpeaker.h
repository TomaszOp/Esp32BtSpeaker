#ifndef _Esp32BtSpeaker_H__
#define _Esp32BtSpeaker_H__

#include "src/A2DP/BluetoothA2DPSink.h"

//static 

#define  DEFAULT_Bck 26;
#define  DEFAULT_Ws 25;
#define  DEFAULT_DataOut 27;

class Esp32BtSpeaker
{
  public:
  Esp32BtSpeaker();
  Esp32BtSpeaker(int bck, int ws, int dataOut);
  ~Esp32BtSpeaker();

BluetoothA2DPSink a2dp_sink;

  int Bck;
  int Ws;
  int DataOut;

  void Start(const char * name); 

  void Start(const char* name, bool auto_reconect);
  void End(bool release_memory=false);

  bool IsConnected();
  esp_a2d_mct_t GetAudioType();
  int GetVolume();
  void Play();
  void Pause();
  void Stop();
  void Next();
  void Previous();
  void FastForward();
  void Rewind();



  private: 

  void AttachI2SPins();
}; 

#endif
