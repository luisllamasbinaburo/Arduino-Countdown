/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
 
#include "CountdownLib.h"

Countdown::Countdown(uint16_t startValue)
{
	Countdown(startValue, nullptr);
}

Countdown::Countdown(uint16_t startValue, CountdownAction onFinish)
{
	this->StartValue = startValue;
	this->Value = startValue;
	this->OnFinish = onFinish;
}

uint16_t Countdown::Tick()
{
	if (this->Value > 0)
	{
		this->Value--;
		if (this->Value == 0 && OnFinish != nullptr) OnFinish();
	}
	return this->Value;
}

void Countdown::Reset()
{
	this->Value = this->StartValue;
}
