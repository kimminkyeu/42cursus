class myObj {
private:
	int	d;
public:
	int getValue_const() const { return d; };
	int getValue_nonConst() { return d; };
	void setValue(const int& _d) { this->d = _d; };
};

void callFunc(const myObj& t)
{
	// WARN:  only const member method can be called!
	t.getValue_nonConst();
	t.getValue_const();
}

int main(void)
{
	myObj t1;

	return (0);
}
