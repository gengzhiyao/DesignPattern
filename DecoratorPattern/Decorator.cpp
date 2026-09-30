#include <iostream>

/** 需求：
 * 三种底层流：文件流、网络流、内存流
 * 多种附加增强功能：加密、缓冲、日志、校验...
 * 需要将上面的任意组合进行搭配
 */
class Stream
{
public:
    virtual void Read( ) = 0;
    virtual void Seek( ) = 0;
    virtual void Write( ) = 0;
    virtual ~Stream( ) = default;
};

class FileStream : public Stream
{
public:
    virtual void Read( ) {}
    virtual void Seek( ) {}
    virtual void Write( ) {}
};

class NetworkStream : public Stream
{
public:
    virtual void Read( ) {}
    virtual void Seek( ) {}
    virtual void Write( ) {}
};

class MemoryStream : public Stream
{
public:
    virtual void Read( ) {}
    virtual void Seek( ) {}
    virtual void Write( ) {}
};

void Crypto( ) { std::cout << "Crypto( )" << std::endl; }; // 加密
void Buffer( ) { std::cout << "Buffer( )" << std::endl; }; // 缓冲
void Log( ) { std::cout << "Log( )" << std::endl; };    // 日志
void Validate( ) { std::cout << "Validate( )" << std::endl; };// 校验

class CryptoFileStream : public FileStream
{
public:
    CryptoFileStream( Stream* s );

public:
    virtual void Read( )
    {
        Crypto( );
        FileStream::Read( );
    }
    virtual void Seek( )
    {
        Crypto( );
        FileStream::Seek( );
    }
    virtual void Write( )
    {
        Crypto( );
        FileStream::Write( );
    }
};

class BufferedFileStream : public FileStream
{
public:
    virtual void Read( )
    {
        Buffer( );
        FileStream::Read( );
    }
    virtual void Seek( )
    {
        Buffer( );
        FileStream::Seek( );
    }
    virtual void Write( )
    {
        Buffer( );
        FileStream::Write( );
    }
};

class CryptoBufferedFileStream : public FileStream
{
public:
    virtual void Read( )
    {
        Crypto( );
        Buffer( );
        FileStream::Read( );
    }

    virtual void Seek( )
    {
        Crypto( );
        Buffer( );
        FileStream::Seek( );
    }
    virtual void Write( )
    {
        Crypto( );
        Buffer( );
        FileStream::Write( );
    }
};

//!----------------------------------------
// > 装饰者模式中，装饰者既是装饰者又是被装饰者，因此也是一种 Warpper 方式
class CryptoStream : public Stream
{
    Stream* m_stream;

public:
    CryptoStream( Stream* s )
        : m_stream( s )
    {
    }

    void Read( ) // override
    {
        Crypto( );
        m_stream->Read( );
    }

    void Seek( )
    {
        Crypto( );
        m_stream->Seek( );
    }

    void Write( )
    {
        Crypto( );
        m_stream->Write( );
    }
};

class BufferStream
{
    Stream* m_stream;

public:
    BufferStream( Stream* s )
        : m_stream( s )
    {
    }
    void Read( )
    {
        Buffer( );
        m_stream->Read( );
    }
};

// 另一种装饰者模式的样例，包装字符串

class Display
{
public:
    virtual int         GetColumns( ) const = 0;
    virtual int         GetRows( ) const = 0;
    virtual std::string GetRowText( int row ) const = 0;
    void                Show( ) const;
    Display( ) = default;
    virtual ~Display( ) = default;
};

inline void Display::Show( ) const
{
    for ( int i = 1; i <= GetRows( ); i++ )
    {
        std::cout << GetRowText( i ) << std::endl;
    }
}

class StringDisplay : public Display
{
public:
    StringDisplay( std::string s )
        : m_str( s )
    {
    }
    int         GetColumns( ) const override;
    int         GetRows( ) const override;
    std::string GetRowText( int row ) const override;

private:
    std::string m_str;
};

inline int StringDisplay::GetRows( ) const
{
    size_t pos = 0;
    int    rowNr = 1;
    while ( ( pos = m_str.find( '\n', pos ) ) != std::string::npos )
    {
        if ( pos != std::string::npos ) rowNr++;
        pos++;
    }
    return rowNr;
}

inline std::string StringDisplay::GetRowText( int row ) const
{
    // row从1开始，小于1直接返回空串（非法行）
    if ( row < 1 ) return "";

    size_t curPos = 0;
    size_t prePos = 0;
    size_t currentLine = 1;

    while ( true )
    {
        // 从curPos查找下一个换行符
        size_t newlinePos = m_str.find( '\n', curPos );

        if ( newlinePos == std::string::npos )
        {
            // 没有更多换行，这是最后一行
            if ( currentLine == row )
            {
                // 从prePos一直到末尾
                return m_str.substr( prePos );
            }
            else
            {
                // 行号超过总行，返回空
                return "";
            }
        }

        // 找到换行符 newlinePos，区间 [prePos , newlinePos) 为本行文本（不含\n）
        if ( currentLine == row )
        {
            return m_str.substr( prePos, newlinePos - prePos );
        }

        // 不是目标行，跳到下一行
        currentLine++;
        prePos = newlinePos + 1;
        curPos = prePos;
    }
}

inline int StringDisplay::GetColumns( ) const
{
    return 20;// 暂时先返回 20 算法后续补充
    size_t maxLen = 0;

    for ( size_t i = 0; i < GetRows( ); i++ )
    {
        // std::max(maxLen,)
    }
}

class Border : public Display
{
protected:
    Display* m_display;

public:
    Border( Display* dis )
        : m_display( dis )
    {
    }
};

class SideBorder : public Border
{
private:
    char m_border;

public:
    SideBorder( Display* d, char margin )
        : Border( d ),
          m_border( margin )
    {
    }
    int         GetColumns( ) const override { return m_display->GetColumns( ) + 2; }
    int         GetRows( ) const override { return m_display->GetRows( ); }
    std::string GetRowText( int row ) const override { return m_border + m_display->GetRowText( row ) + m_border; }
};

class FullBorder : public Border
{
private:
    char m_border;
    public:
    FullBorder( Display* d, char border )
        : Border( d ),
          m_border( border )
    {
    }

    int         GetColumns( ) const override { return m_display->GetColumns( ) + 2; }
    int         GetRows( ) const override { return m_display->GetRows( )+2; }
    std::string GetRowText( int row ) const override { return m_border + m_display->GetRowText( row ) + m_border; }
};

int main( )
{
    Stream*       s1 = new FileStream;
    CryptoStream* s2 = new CryptoStream( s1 );
    BufferStream* s3 = new BufferStream( s2 );

    s2->Read( );
    s3->Read( );

    Display* pDisplay = new StringDisplay( "abcd\nefg" );
    Display* pd = new SideBorder( new StringDisplay( "aaaa" ), '|' );
    pd->Show( );

    Display* s = new FullBorder( pd, '-' );
    s->Show( ); // 全包边框算法有问题 暂时不理
}
