class Inventory
{
	Rune* runes;
	int current; //index
	int capacity; //size

	void copy(Inventory const& other)
	{
		current = other.current;
		capacity = other.capacity;

		runes = new Rune[capacity];
		for (int i = 0; i <= current; i++)
			runes[i] = other.runes[i];
	}

	void remove()
	{
		delete[] runes;
	}
  
  void resize()
	{
		capacity *= 2;
		Rune *runes2 = new Rune[capacity];
		for (int i = 0; i < capacity; i++)
		{
			runes2[i] = runes[i];
		}
		delete[] runes;
		runes = runes2;
	}

public:
	Inventory()
	{
		current = -1;
		capacity = 10;
		runes = new Rune[capacity];
	}

	void add(Rune const& rune)
	{
		if(current==capacity-1)
		{
			resize();
		}

		current++;
		runes[current] = rune;
	}

	Inventory(Inventory const& other)
	{
		copy(other);
	}

	Inventory& operator=(Inventory const& other)
	{

		if (this != &other)
		{
			remove();
			copy(other);
		}

		return *this;
	}

	~Inventory()
	{
		remove();
	}
};

void testInventory()
{

	while(true)
	{
		Inventory inv;
		for (int i = 0; i < 1000; i++)
		{
			Rune r;
			inv.add(r);
		}
	}
}

int main()
{
	testInventory();
  return 0;
}
