package com.example.demo;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;

import java.io.*;
import java.net.URL;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.ResourceBundle;

public class HelloController implements Initializable {
    ArrayList<Musteri> musteriArrayList=new ArrayList<>();
    String adsoyad,meslek ,stringurun;
    LocalDate dogumtarihi;
    int urunadet,kimlikno;
    @FXML
    private Label welcomeText;
    @FXML ComboBox<String> customerjob;
    @FXML ComboBox<String>  urun;
    @FXML ComboBox<String>  screencostumercombobox;
    @FXML
    DatePicker birthdate;
    @FXML
    Spinner<Integer>  adet;
    @FXML
    TextField customernameandsurname;
    @FXML
    TextField customeridnumber;
    @FXML
    TextField screenkimlik;
    @FXML
    TextField screenjob;
    @FXML
    TextField screenbirth;
    @FXML
    TextField screenurun    ;
    @FXML
    TextField screenadet;
    @FXML
    void MusteriKayit(ActionEvent event) {
        meslek=customerjob.getValue();
        dogumtarihi=birthdate.getValue();
        stringurun=urun.getValue();
        urunadet=adet.getValue();
        if(customernameandsurname.getText().isEmpty()||customeridnumber.getText().isEmpty()){
            Alert hata=new Alert(Alert.AlertType.ERROR);
            hata.setTitle("Hata!");
            hata.setHeaderText(" tc veya ad soyad girilmedi");
            hata.show();;
            return;
        }
        adsoyad=customernameandsurname.getText();
        kimlikno=Integer.parseInt(customeridnumber.getText());
        for (int i = 0; i <musteriArrayList.size() ; i++) {
            if(kimlikno==musteriArrayList.get(i).getKimlikno()){
                Alert hata=new Alert(Alert.AlertType.ERROR);
                hata.setTitle("Hata!");
                hata.setHeaderText(kimlikno +" numaralı müşteri kayıtlı");
                hata.show();;
                return;
            }
        }

        Musteri musteri=new Musteri(adsoyad,meslek,stringurun,dogumtarihi,kimlikno,urunadet);
        musteriArrayList.add(musteri);
        try {
            FileOutputStream fos=new FileOutputStream("kitapbilgileri.dat");
            ObjectOutputStream obs=new ObjectOutputStream(fos);
            obs.writeObject(musteriArrayList);
            fos.close();
            obs.close();
            Alert bilgi=new Alert(Alert.AlertType.CONFIRMATION);
            bilgi.setTitle("Bilgi");
            bilgi.setHeaderText(musteri.getAdsoyad()+" kişisi kaydedildi...");
            bilgi.show();;
            screencostumercombobox.getItems().add(musteri.getAdsoyad());




        }
        catch (Exception e){
        e.printStackTrace();
        }
    }

    @FXML
    void MusteriSil(ActionEvent event) {
        try {
            int index= screencostumercombobox.getSelectionModel().getSelectedIndex();
            if(index<0){
                Alert hata=new Alert(Alert.AlertType.ERROR);
                hata.setTitle("Hata!");
                hata.setHeaderText(" Silinecek kayıt bulunamadı");
                hata.show();;
                return;
            }
             adsoyad=musteriArrayList.get(index).getAdsoyad();
            screencostumercombobox.getItems().remove(index);
            screenadet.clear();
            screenbirth.clear();
            screenjob.clear();
            screenurun.clear();
            screenkimlik.clear();
            musteriArrayList.remove(index);


            FileOutputStream fos=new FileOutputStream("Musteribilgileri.dat");
            ObjectOutputStream obs=new ObjectOutputStream(fos);
            obs.writeObject(musteriArrayList);
            fos.close();
            obs.close();
            Alert bilgi=new Alert(Alert.AlertType.INFORMATION);
            bilgi.setTitle("Bilgi");
            bilgi.setHeaderText(adsoyad+" kişisi silindi...");
            bilgi.show();;


        }
        catch (Exception e){
        e.printStackTrace();
        }


    }

    @FXML
    void Musterisec(ActionEvent event) {
        int index= screencostumercombobox.getSelectionModel().getSelectedIndex();
        if(index<0) return;
        screenkimlik.setText(String.valueOf(musteriArrayList.get(index).getKimlikno()));

         screenjob.setText(musteriArrayList.get(index).getMeslek());

         screenbirth.setText(String.valueOf( musteriArrayList.get(index).getDogumtarih()));

         screenurun .setText(musteriArrayList.get(index).getUrun())   ;

         screenadet.setText(String.valueOf( musteriArrayList.get(index).getUrunadet()));
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        customerjob.setItems(FXCollections.observableArrayList("doktor","mühendis","astronot"));
        customerjob.getItems().add("pilot");
        urun.setItems(FXCollections.observableArrayList("dolap","masa"));
        adet.setValueFactory(new SpinnerValueFactory.IntegerSpinnerValueFactory(1,300,1,1));
        try{
            FileInputStream fis=new FileInputStream("Musteribilgileri.dat");
            ObjectInputStream ois=new ObjectInputStream(fis);
            musteriArrayList= (ArrayList<Musteri>) ois.readObject();
            ois.close();
            for (int i = 0; i <musteriArrayList.size() ; i++) {
                screencostumercombobox.getItems().add(musteriArrayList.get(i).getAdsoyad());
            }
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}
