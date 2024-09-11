//---------------------------------------------------------------------------

#ifndef CValueH
#define CValueH

//---------------------------------------------------------------------------
template <typename T>
struct CValue {

private:
	T m_value;
	bool m_bIsChange;

public:
	void init(const T& initialValue) {
		m_value = initialValue;
		m_bIsChange = false;
    }

	void change(const T& newValue) {
		if (m_value != newValue) {
			m_value = newValue;
			m_bIsChange = true;
        }
    }

    T get() const {
        return m_value;
    }

	bool isChange() const {
        return m_bIsChange;
    }
};

#endif
