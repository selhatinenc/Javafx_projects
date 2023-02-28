package com.example.demo;

import java.io.Serializable;
import java.time.LocalDate;

public class Musteri implements Serializable {
    private String adsoyad,meslek,urun;
    private LocalDate dogumtarih;
    private Integer kimlikno,urunadet;

    public String getAdsoyad() {
        return adsoyad;
    }

    public void setAdsoyad(String adsoyad) {
        this.adsoyad = adsoyad;
    }

    public String getMeslek() {
        return meslek;
    }

    public void setMeslek(String meslek) {
        this.meslek = meslek;
    }

    public String getUrun() {
        return urun;
    }

    public void setUrun(String urun) {
        this.urun = urun;
    }

    public LocalDate getDogumtarih() {
        return dogumtarih;
    }

    public void setDogumtarih(LocalDate dogumtarih) {
        this.dogumtarih = dogumtarih;
    }

    public Integer getKimlikno() {
        return kimlikno;
    }

    public void setKimlikno(Integer kimlikno) {
        this.kimlikno = kimlikno;
    }

    public Integer getUrunadet() {
        return urunadet;
    }

    public void setUrunadet(Integer urunadet) {
        this.urunadet = urunadet;
    }

    public Musteri(String adsoyad, String meslek, String urun, LocalDate dogumtarih, Integer kimlikno, Integer urunadet) {
       super();
        this.adsoyad = adsoyad;
        this.meslek = meslek;
        this.urun = urun;
        this.dogumtarih = dogumtarih;
        this.kimlikno = kimlikno;
        this.urunadet = urunadet;
    }
}
