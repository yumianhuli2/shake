#ifndef MACRO_PROPERTY_HPP
#define MACRO_PROPERTY_HPP

//----------------------------------------------------------------
#define PROPERTY_RW( type, var ) \
private: \
    type m_##var; \
public: \
    const type& var() const \
    { \
        return m_##var; \
    } \
\
    type& var() \
    { \
       return m_##var; \
    }

//----------------------------------------------------------------
#define PROPERTY_R( type, var ) \
private: \
    type m_##var; \
public: \
    const type& get_##var() const \
    { \
        return m_##var; \
    }

//----------------------------------------------------------------
#define PROPERTY_W( type, var ) \
private: \
    type m_##var; \
public: \
    void set_##var( const type& v) \
    { \
        m_##var = v; \
    }

#endif // MACRO_PROPERTY_HPP
