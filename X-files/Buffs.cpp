//Идеята на следващите структори е че съдържат количеството "бъфове", които героя може да използва.
//Представете си, че той има една торба "бъфове", която от своя страна си има капацитет и текущ брой елементи вътре в нея
//Можем да вадим и да слагаме в торбата, както и да и пришиваме допълнителни отделения, където да слагаме още "бъфове"
class IntellectBuff
{
	int capacity;
	int remaining;
	
public:
	IntellectBuff()
	{
		capacity=5;
		remaining=0;
	}
	
	IntellectBuff(int _capacity, int _remaining)
	{
		capacity=_capacity;
		remaining=_remaining;
	}
	
	IntellectBuff(IntellectBuff const& other)
	{
		capacity=other.capacity;
		remaining=other.remaining;
	}
	
	void setCapacity(int _capacity)
	{
		capacity=_capacity;
	}
	
	void setRemaining(int _remaining)
	{
		remaining=_remaining;
	}
	
	int getCapacity()
	{
		return capacity;
	}
	
	int getRemaining()
	{
		return remaining;
	}
	
	void increaseCapacity(int bonuscapacity)
	{
		capacity+=bonuscapacity;
	}
	
	void gainBuff()
	{
		if(remaining!=capacity) remaining++;
	}
	
	void useBuff()
	{
		if(remaining!=0) remaining--;
	}
	friend ostream& operator<<(ostream& os,const IntellectBuff& buff)
	{
		os<<"Remaining "<<buff.remaining<<" intellect buffs of "<<buff.capacity<<" possible"<<endl;
		return os;
	}
	
};

class SpeedBuff
{
	int capacity;
	int remaining;
	
public:
	SpeedBuff()
	{
		capacity=5;
		remaining=0;
	}
	
	SpeedBuff(int _capacity, int _remaining)
	{
		capacity=_capacity;
		remaining=_remaining;
	}
	
	SpeedBuff(SpeedBuff const& other)
	{
		capacity=other.capacity;
		remaining=other.remaining;
	}
	
	void setCapacity(int _capacity)
	{
		capacity=_capacity;
	}
	
	void setRemaining(int _remaining)
	{
		remaining=_remaining;
	}
	
	int getCapacity()
	{
		return capacity;
	}
	
	int getRemaining()
	{
		return remaining;
	}
	
	void increaseCapacity(int bonuscapacity)
	{
		capacity+=bonuscapacity;
	}
	
	void gainBuff()
	{
		if(remaining!=capacity) remaining++;
	}
	
	void useBuff()
	{
		if(remaining!=0) remaining--;
	}
	
	friend ostream& operator<<(ostream& os, const SpeedBuff& buff)
	{
		os<<"Remaining "<<buff.remaining<<" speed buffs of "<<buff.capacity<<" possible"<<endl;
		return os;
	}
};

class StrengthBuff
{
	int capacity;
	int remaining;
	
public:
  	StrengthBuff()
	{
		capacity=5;
		remaining=0;
	}
	
	StrengthBuff(int _capacity, int _remaining)
	{
		capacity=_capacity;
		remaining=_remaining;
	}
	
	StrengthBuff(StrengthBuff const& other)
	{
		capacity=other.capacity;
		remaining=other.remaining;
	}
	
	void setCapacity(int _capacity)
	{
		capacity=_capacity;
	}
	
	void setRemaining(int _remaining)
	{
		remaining=_remaining;
	}
	
	int getCapacity()
	{
		return capacity;
	}
	
	int getRemaining()
	{
		return remaining;
	}
	
	void increaseCapacity(int bonuscapacity)
	{
		capacity+=bonuscapacity;
	}
	
	void gainBuff()
	{
		if(remaining!=capacity) remaining++;
	}
	
	void useBuff()
	{
		if(remaining!=0) remaining--;
	}
	
	friend ostream& operator<<(ostream& os,const StrengthBuff& buff)
	{
		os<<"Remaining "<<buff.remaining<<" strength buffs of "<<buff.capacity<<" possible"<<endl;
		return os;
	}
	
};
