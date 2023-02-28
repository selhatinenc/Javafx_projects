package com.example.sevgiepozhan191030043;

import java.io.Serializable;
import java.time.LocalDate;

public class kitap implements Serializable {
       private String Kitapadi,Isbnadi,yazaradi,kitabin_dili,kitabin_turu,yayinevi,basimyili,yayintarihi;
     //   private LocalDate yayintarihi;

    public String getKitapadi() {
        return Kitapadi;
    }

    public void setKitapadi(String kitapadi) {
        Kitapadi = kitapadi;
    }

    public String getIsbnadi() {
        return Isbnadi;
    }

    public void setIsbnadi(String isbnadi) {
        Isbnadi = isbnadi;
    }

    public String getYazaradi() {
        return yazaradi;
    }

    public void setYazaradi(String yazaradi) {
        this.yazaradi = yazaradi;
    }

    public String getKitabin_dili() {
        return kitabin_dili;
    }

    public void setKitabin_dili(String kitabin_dili) {
        this.kitabin_dili = kitabin_dili;
    }

    public String getKitabin_turu() {
        return kitabin_turu;
    }

    public void setKitabin_turu(String kitabin_turu) {
        this.kitabin_turu = kitabin_turu;
    }

    public String getYayinevi() {
        return yayinevi;
    }

    public void setYayinevi(String yayinevi) {
        this.yayinevi = yayinevi;
    }

    public String getBasimyili() {
        return basimyili;
    }

    public void setBasimyili(String basimyili) {
        this.basimyili = basimyili;
    }

    public String getYayintarihi() {
        return yayintarihi;
    }

    public void setYayintarihi(String yayintarihi) {
        this.yayintarihi = yayintarihi;
    }

    public kitap(String kitapadi, String isbnadi, String yazaradi, String kitabin_dili, String kitabin_turu, String yayinevi, String basimyili, String yayintarihi) {
        Kitapadi = kitapadi;
        Isbnadi = isbnadi;
        this.yazaradi = yazaradi;
        this.kitabin_dili = kitabin_dili;
        this.kitabin_turu = kitabin_turu;
        this.yayinevi = yayinevi;
        this.basimyili = basimyili;
        this.yayintarihi = yayintarihi;
    }
}
