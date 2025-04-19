# ft_irc

42 okulunun C++ projesi olan ft_irc, RFC 2812 protokolüne uygun bir Internet Relay Chat (IRC) sunucusu implementasyonudur.

## 🌐 Proje Hakkında

ft_irc, modern C++ kullanarak temel bir IRC sunucusu oluşturmayı amaçlayan bir projedir. Proje, ağ programlama, soket iletişimi ve eşzamanlı programlama konularını kapsamaktadır.

## 💻 Teknolojiler

- C++98 Standardı
- POSIX Soketleri
- TCP/IP Protokolü
- I/O Multiplexing (select/poll/epoll)
- RFC 2812 (IRC Protokolü)

## 🛠️ Kurulum

### Gereksinimler
- GCC/G++ Derleyici
- Make
- POSIX Uyumlu İşletim Sistemi
- CMake (opsiyonel)

### Derleme ve Çalıştırma

1. Projeyi klonlayın:
```bash
git clone https://github.com/[kullanıcı-adı]/ft_irc.git
cd ft_irc
```

2. Projeyi derleyin:
```bash
make
```

3. Sunucuyu başlatın:
```bash
./ircserv <port> <password>
```

## 📝 Özellikler

### IRC Protokol Özellikleri
- [x] Kullanıcı Kaydı ve Kimlik Doğrulama
- [x] Kanal Oluşturma ve Yönetimi
- [x] Özel Mesajlaşma
- [x] Operatör Komutları
- [x] Kanal Modları

### Sunucu Özellikleri
- [x] Çoklu İstemci Desteği
- [x] Non-blocking I/O
- [x] Buffer Yönetimi
- [x] Hata İşleme
- [x] Güvenlik Kontrolleri

### Desteklenen IRC Komutları
- [x] NICK - Kullanıcı adı değiştirme
- [x] USER - Kullanıcı kaydı
- [x] JOIN - Kanala katılma
- [x] PART - Kanaldan ayrılma
- [x] PRIVMSG - Özel mesaj gönderme
- [x] NOTICE - Bildirim gönderme
- [x] KICK - Kullanıcıyı kanaldan atma
- [x] MODE - Kanal/kullanıcı modlarını değiştirme
- [x] TOPIC - Kanal konusunu değiştirme
- [x] QUIT - Sunucudan ayrılma

## 🔧 Sunucu Konfigürasyonu

### Temel Ayarlar
```cpp
struct ServerConfig {
    int port;                    // Sunucu portu
    std::string password;        // Sunucu şifresi
    int max_clients;            // Maksimum istemci sayısı
    std::string server_name;    // Sunucu adı
    std::string motd;           // Günün mesajı
};
```

### Kanal Ayarları
```cpp
struct ChannelConfig {
    int max_users;              // Kanal başına maksimum kullanıcı
    bool invite_only;           // Sadece davetli kullanıcılar
    bool topic_protection;      // Konu değiştirme koruması
    std::string modes;          // Varsayılan kanal modları
};
```

## 🎯 42 Proje Gereksinimleri

### Zorunlu Kısım
- [x] TCP/IP Üzerinden Bağlantı
- [x] Gerçek IRC İstemcisi ile Uyumluluk
- [x] Kanal Oluşturma ve Yönetimi
- [x] Özel Mesajlaşma
- [x] Dosya Aktarımı

### Bonus Özellikler
- [x] Bot Desteği
- [x] SSL/TLS Şifreleme
- [x] Dosya Aktarım Protokolü
- [x] Kanal Operatör Sistemi
- [x] Özel Sunucu Komutları

## 📚 IRC Komut Örnekleri

### Kullanıcı Kaydı
```
PASS <şifre>
NICK <kullanıcı_adı>
USER <kullanıcı> <mod> * :<gerçek_ad>
```

### Kanal İşlemleri
```
JOIN #kanal
PART #kanal
PRIVMSG #kanal :Merhaba Dünya!
MODE #kanal +o kullanıcı
```

## 🔒 Güvenlik Özellikleri

1. Kullanıcı Doğrulama
   - Şifre kontrolü
   - Nick çakışması kontrolü
   - Flood koruması

2. Kanal Güvenliği
   - Mod sistemi
   - Ban listesi
   - Invite-only kanallar

3. Sunucu Güvenliği
   - DDoS koruması
   - Rate limiting
   - Input sanitization

## 🐛 Hata Ayıklama

### Yaygın Sorunlar
1. Bağlantı Sorunları
   - Port kullanılabilirliğini kontrol edin
   - Firewall ayarlarını kontrol edin
   - Socket hatalarını kontrol edin

2. Bellek Sorunları
   - Bellek sızıntılarını kontrol edin
   - Buffer overflow kontrolü yapın
   - Resource cleanup kontrolü yapın

## 📈 Performans İyileştirmeleri

1. Network Optimizasyonu
   - Buffer boyutu optimizasyonu
   - Non-blocking I/O kullanımı
   - Connection pooling

2. Bellek Yönetimi
   - Smart pointer kullanımı
   - Memory pool implementasyonu
   - Etkin kaynak yönetimi

## 🔍 Test Etme

1. Unit Testler
```bash
make test
./irc_tests
```

2. Bağlantı Testi
```bash
nc localhost <port>
```

3. IRC İstemcisi ile Test
```
/server localhost <port>
/pass <şifre>
```

## 👥 Katkıda Bulunma

1. Bu repository'yi fork edin
2. Feature branch'i oluşturun (`git checkout -b feature/AmazingFeature`)
3. Değişikliklerinizi commit edin (`git commit -m 'Add some AmazingFeature'`)
4. Branch'inizi push edin (`git push origin feature/AmazingFeature`)
5. Pull Request oluşturun

## 📝 Lisans

Bu proje [MIT](LICENSE) lisansı altında lisanslanmıştır.

## 📚 Kaynaklar

- [RFC 2812 - IRC Protokol Spesifikasyonu](https://tools.ietf.org/html/rfc2812)
- [Modern IRC İstemci Protokolü](https://modern.ircdocs.horse/)
- [IRC Daemon Programlama](https://www.alien.net.au/irc/irc2numerics.html)

---

⭐️ Bu projeyi beğendiyseniz yıldız vermeyi unutmayın!
