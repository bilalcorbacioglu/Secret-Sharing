# Secret Sharing

[![Secret-Sharing](https://img.shields.io/badge/release-v1.0.0-red.svg)](https://github.com/bilalcorbacioglu/Secret-Sharing/releases) [![Secret-Sharing](https://travis-ci.org/bilalcorbacioglu/Secret-Sharing.svg?branch=master)](https://travis-ci.org/bilalcorbacioglu/Secret-Sharing) [![Secret-Sharing](https://img.shields.io/badge/consistent-%2570-brightgreen.svg)](https://github.com/bilalcorbacioglu/Secret-Sharing) [![Secret-Sharing](https://img.shields.io/badge/code quality-B-blue.svg?style=flat-square)](https://github.com/bilalcorbacioglu/Secret-Sharing)  [![Secret-Sharing](https://img.shields.io/badge/license-GPL-yellowgreen.svg)](https://github.com/bilalcorbacioglu/Secret-Sharing/blob/master/LICENSE) 

  1979'da Blackley ve Shamir tarafından ayrı zamanlarda önerilmıştir. Amaç gizli olan verinin "n" kişiye dağıtılmasıdır. Sır paylaşma şemalarından "n" kişiye gönderilen bilgi, pay olarak adlandırılır. Katılımcılardan "k" tanesi yada daha fazlasının bir araya gelerek, ellerindeki pay bilgilerini kullanmalarıyla gizli veri ortaya çıkar.
    
  Literatürde bu yöntemin bir diğer ismide (k,n) Eşik Şeması dır. Shamir tarafında önerilen Sır Paylaşımı yöntemi "Polinom Tabanlı" dır. Blackley tarafından önerilen Sır Paylaşımı yöntemini hiper düzlem denklemlerinin geometrik özelliklerinden faydalanmaktadır.
    
  Ufak bir dipnot düşelim: 
  
    "Kriptografi gizli görüntüyü şifreleyerek farklı ve anlamsız bir görüntüye çevirirken; Steganografi, gizli görüntüyü farklı bir görüntü içerisine saklamaktadır." 
  
  Paylaştırılan görüntülerin herhangi birisinin bozulması veyahut kaybolması durumunda gizli görüntü elde edilemez. 2002 yılında Thien ve Lin bu yöntemin (Sır Paylaşımı) gizli görüntü paylaşımında kullanılmasını önermişlerdir.
  
    Bu projede Shamir tarafından ortaya atılan Sır Paylaşımı yöntemi gösterilecek.
    
##Shamir'in Sır Paylaşma Şeması

  Amaç "S" ile gösterilen gizli veriyi "n" tane kişiye dağıtmak ve "k" tanesini birleştirerek gizli verimi elde etmektir. Her bir kişiye bir pay değeri düşecektir. Öncelikle pay değerlerimi oluşturacak olan fonksiyon belirlenir.
  
    f(x) = (S + ax + bx^2 + cx^3 + ... + zx^(k-1)) mod p
  
  Burada a,b,c,z degerlerinin tanım aralığı [0,p-1] dir ve bu aralıktan rastgele olarak seçilirler. ("p" değeri görüntü saklarken 251 alınırken, başka bir verinin saklanırken kaç alınması gerektiği tamamen size kalmıştır) Ardından 1.payda hesaplanır, f(1) 1.paydanın değerinin belirler. Aynı şekilde 2.paydanın değeride f(2) ile hesaplanır, "n" tane paydanın değeri hesaplandıktan sonra rastgele "k" tanesi seçilir. Seçilen bu k tane payda Lagrange'ın interpolasyonunda gizli verinin elde edilmesinde kullanılır.
  
###Lagrange İnterpolasyonu

 Lagrange interpolasyonunda (n+1) noktadaki (x,y)(x1,y1)(x2,y2) değeri bilinen f(x) fonksiyonuna, bu noktalardaki değerleri eşit olan bir L(x) polinomu uydurulur. Hesaplama örneği aşağıdaki gibidir.
![Lagrange-İnterpolasyonu](http://komplexify.com/images/2007/Lagrange.gif)

  Ardından f(x) ve "S" verimizi elde etmek için (1.pay için üretilen değer * l1) + (2.pay için üretilen değer * l2) + (3.pay için üretilen değer * l3) + ... bize f(x) fonksiyonumuzu verecektir.

    
##Shamir Yöntemi ile Gizli Görüntü Paylaşımı

  Paylaşılan görüntünün gri seviye olduğu varsayılmıştır. Her bir piksel değerinin [0,255] aralığında değerler alabilecek olması sebebi ile, gizli görüntünün paylaşımından önce, piksel parlaklık değerleri üzerinde ön işlem yapılmaktadır. Shamir'in yönteminde "p" ile gösterilen ve sır olarak dağıtılacak olan verinin aralığını belirleyen bir asal sayı değeri kullanılmaktadır. Lin ve Tsai yöntemin görüntü paylaşımına adaptasyonu için belirlediği değer 251 dir. Çünkü [0,255] arasındaki en büyük asal sayı 251 dir. Bu nedenle gizli görüntünün bütün piksel değerleri 251'e göre mod işlemine tabi tutulur. Buradan sonra aslında karşımıza iki adet algoritma çıkmaktadır.
  
      1- Paylaştırma Algoritması
      2- Yeniden Yapılandırma
  
###Paylaştırma Algoritması

    1- Gizli Gorüntüdeki tüm piksellerin 251'e göre modu alınır. Böylelikle piksel değerlerini [0,250] arasına çekmiş oluyoruz.
    2- 1.Piksel alınır ve Shamir'in Sır Paylaşma Şemasında anlattığımız işlemler yapılır.
      f(x) = (a+ bx + ... + zx^(k-1))mod 251
    3- n tane paya gönderilecek olan bilgiler hesaplanır.
      (1,f(1)),(2,f(2)),...,(n,f(n))
    4- Adım 2 ve 3 tum piksel değerleri paylaştırılana kadar tekrarlanır.
    
  Üretilen payların büyüklüğü gizli görüntünün 1/k sı kadarda olsa, bu programda bu geçerli değildir ve üretilen payların büyüklüğü orjinal resmin büyüklüğü kadar olmaktadır.
  Adım 2'de gerçekleştirilen yerdeğiştirme(Permütasyon) işlemi sistemin güvenirliliğini arttırmaktadır.

###Yeniden Yapılandırma

    1- Tüm paylardaki 1.piksel değeri toplanır. 251 e göre modu alınır. Bu gizli görüntüdeki 1.pikselin değerini verir.
    2- Tüm piksel değerleri için 1.Adım gerçekleştirilir.

      
Teorik olarak Sır Paylaşımı budur ve bu şekilde gerçekleştirilir. Bu aşamadan sonra kod kısmına geçiş yapabilir ve kod üzerinden sır paylaşımı algoritmasını irdeleyebiliriz.

#####Alıntı
    PROF. DR. Vasif Vagifoğlu NABİYEV, "Algoritmalar",4.Baskı 256-260

##Settings
  * Paylaştırma
  
  * İlk olarak bmptotxt.cpp derlenir. Bu bize pikseller.txt adlı dosyayı üretecektir.
  * Son olarak main.cpp, secret.cpp ile birlikte linking aşamasından geçirilir.
  

  * Yeniden Yapılandırma

  * solve.cpp nin derlenmesi  yeterli olacaktır.
  

##Run

* Paylaştırma

```bash
$ g++ -c main.cpp
$ g++ -c secret.cpp
$ g++ -c -I ../include secret.cpp
$ g++ -c -D NDEBUG secret.cpp
$ g++ -c -D NDEBUG=3 secret.cpp
$ g++ -c -O2 secret.cpp
$ g++ -o secret main.o secret.o
./secret
```
* Yeniden Yapılandırma

```bash
$ g++ -c solve.cpp
$ g++ -o solve solve.o
./solve
```

##Example

Programımızdan ufak bir örnek verelim. Gizli resmimizi "8" kişi içinden rastgele "4" kişiye dağıtalım.


Orjinal Resim

![Lena](http://internproject.zz.mu/res/Lenna.bmp)

Paylar

![Pay-0](http://internproject.zz.mu/res/0.bmp)
![Pay-1](http://internproject.zz.mu/res/1.bmp)
![Pay-2](http://internproject.zz.mu/res/2.bmp)
![Pay-3](http://internproject.zz.mu/res/3.bmp)

Elde Edilen Çıktı

![Cikti](http://internproject.zz.mu/res/new.bmp)

### Credits

 * [Bilal Çorbacıoğlu](https://github.com/bilalcorbacioglu)


###License

The GNU General Public License - see [LICENSE.md](https://github.com/bilalcorbacioglu/Secret-Sharing/blob/master/LICENSE) for more details
