#include "Esp32BtSpeaker.h"
#include "Arduino.h"


Esp32BtSpeaker::Esp32BtSpeaker()
{
    this->Bck = DEFAULT_Bck;
    this->Ws = DEFAULT_Ws;   
    this->DataOut = DEFAULT_DataOut; 

    AttachI2SPins();
}

Esp32BtSpeaker::Esp32BtSpeaker(int bck, int ws, int dataOut)
{
    this->Bck = bck;
    this->Ws =  ws;   
    this->DataOut = dataOut; 

    AttachI2SPins();
}

Esp32BtSpeaker::~Esp32BtSpeaker() 
{

}

void Esp32BtSpeaker::AttachI2SPins()
{  
   delay(1000);
    i2s_pin_config_t my_pin_config = {
        .bck_io_num = this->Bck,
        .ws_io_num = this->Ws,
        .data_out_num = this->DataOut,
        .data_in_num = I2S_PIN_NO_CHANGE
    };

    a2dp_sink.set_pin_config(my_pin_config);
    delay(1000);
}
 
void Esp32BtSpeaker::Start(const char * name)
{    
    Serial.println("Start BtSpeaker");
    delay(1000);
    a2dp_sink.start(name); 
    delay(1000);
    Serial.println(name);
}
 
void Esp32BtSpeaker::Start(const char* name, bool auto_reconect)
{    
    a2dp_sink.start(name, auto_reconect); 
}

void Esp32BtSpeaker::End(bool release_memory)
{    
    a2dp_sink.end(release_memory);
}

bool Esp32BtSpeaker::IsConnected()
{    
    return a2dp_sink.is_connected();
}

esp_a2d_mct_t Esp32BtSpeaker::GetAudioType()
{    
    return a2dp_sink.get_audio_type();
}

int Esp32BtSpeaker::GetVolume()
{    
    return a2dp_sink.get_volume();
}

void Esp32BtSpeaker::Play()
{    
    a2dp_sink.play();
}

void Esp32BtSpeaker::Pause()
{    
    a2dp_sink.pause();
}

void Esp32BtSpeaker::Stop()
{    
    a2dp_sink.stop();
}

void Esp32BtSpeaker::Next()
{    
    a2dp_sink.next();
}

void Esp32BtSpeaker::Previous()
{    
    a2dp_sink.previous();
}

void Esp32BtSpeaker::FastForward()
{    
    a2dp_sink.fast_forward();
}

void Esp32BtSpeaker::Rewind()
{    
    a2dp_sink.rewind();
}






