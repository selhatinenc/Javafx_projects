package com.example.sevgiepozhan191030043;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.VBox;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.URL;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.ResourceBundle;

public class HelloController implements Initializable {
    ArrayList<kitap> kitap_arraylist=new ArrayList<>();
    private String thisKitapadi,thisIsbnadi,thisyazaradi,thiskitabin_dili,thiskitabin_turu,thisyayinevi,thisbasimyili,thisyayintarihi;

    @FXML
    private VBox Vbox;
    @FXML
    private AnchorPane anchorpane;
    @FXML
    private Spinner<Integer> basimyiliid;

    @FXML
    private DatePicker yayintarihid;

    @FXML
    private TextField isbnid;

    @FXML
    private Button kaydetbuttonid;

    @FXML
    private ComboBox<String> kitapdilid;

    @FXML
    private TextField kitapid;

    @FXML
    private ComboBox<String> kitapseccombobox;

    @FXML
    private ComboBox<String> kitapturid;

    @FXML
    private TextField screenbasimyili;

    @FXML
    private TextField screenisbnno;

    @FXML
    private TextField screenkitapdili;

    @FXML
    private Button screenkitapsil;

    @FXML
    private TextField screenkitapturu;

    @FXML
    private TextField screenyayinevi;

    @FXML
    private TextField screenyayintarihi;

    @FXML
    private TextField screenyazaradi;

    @FXML
    private ComboBox<String> yayineviid;

    @FXML
    private TextField yazaradiid;

    @FXML
    void bookKayit(ActionEvent event) {


        if(kitapid.getText().isEmpty()||isbnid.getText().isEmpty()){
            Alert hata=new Alert(Alert.AlertType.ERROR);
            hata.setTitle("Hata!");
            hata.setHeaderText(" Kitap adı ve ISBN numarasını giriniz lütfen");
            hata.show();;
            return;
        }
        thisKitapadi=kitapid.getText();
        thisIsbnadi=isbnid.getText();
        thisyazaradi=yazaradiid.getText();
        thisyayintarihi=yayintarihid.getValue().toString();
        thiskitabin_dili=kitapdilid.getValue();
        thiskitabin_turu=kitapturid.getValue();
        thisbasimyili=basimyiliid.getValue().toString();
        thisyayinevi=yayineviid.getValue();


        for (int i = 0; i <kitap_arraylist.size() ; i++) {
            if(thisIsbnadi.equals(kitap_arraylist.get(i).getIsbnadi())){
                Alert hata=new Alert(Alert.AlertType.ERROR);
                hata.setTitle("Hata!");
                hata.setHeaderText(thisIsbnadi +" numaralı kitap kayıtlı");
                hata.show();;
                return;
            }
        }

        kitap kitap=new kitap(thisKitapadi,thisIsbnadi,thisyazaradi,thiskitabin_dili,thiskitabin_turu,thisyayinevi,thisbasimyili,thisyayintarihi);
        kitap_arraylist.add(kitap);
        try {
            FileOutputStream fos=new FileOutputStream("kitapbilgileri.dat");
            ObjectOutputStream obs=new ObjectOutputStream(fos);
            obs.writeObject(kitap_arraylist);
            fos.close();
            obs.close();
            Alert bilgi=new Alert(Alert.AlertType.CONFIRMATION);
            bilgi.setTitle("Bilgi");
            bilgi.setHeaderText(thisKitapadi+" kitabı kaydedildi...");
            bilgi.show();;
            kitapseccombobox.getItems().add(kitap.getKitapadi());




        }
        catch (Exception e){
            e.printStackTrace();
        }
    }

    @FXML
    void bookSil(ActionEvent event) {
        try {
            int index= kitapseccombobox.getSelectionModel().getSelectedIndex();
            if(index<0){
                Alert hata=new Alert(Alert.AlertType.ERROR);
                hata.setTitle("Hata!");
                hata.setHeaderText(" Silinecek kayıt bulunamadı");
                hata.show();;
                return;
            }
            thisKitapadi=kitap_arraylist.get(index).getKitapadi();
            kitapseccombobox.getItems().remove(index);
            screenisbnno.clear();
            screenyazaradi.clear();
            screenyayintarihi.clear();
            screenkitapdili.clear();
            screenkitapturu.clear();
            screenbasimyili.clear();
            screenyayinevi.clear();

            kitap_arraylist.remove(index);


            FileOutputStream fos=new FileOutputStream("kitapbilgileri.dat");
            ObjectOutputStream obs=new ObjectOutputStream(fos);
            obs.writeObject(kitap_arraylist);
            fos.close();
            obs.close();
            Alert bilgi=new Alert(Alert.AlertType.INFORMATION);
            bilgi.setTitle("Bilgi");
            bilgi.setHeaderText(thisKitapadi+" kitabı silindi...");
            bilgi.show();;


        }
        catch (Exception e){
            e.printStackTrace();
        }
    }

    @FXML
    void booksec(ActionEvent event) {
        
        int index= kitapseccombobox.getSelectionModel().getSelectedIndex();
        if(index<0) return;

        screenisbnno.setText(String.valueOf(kitap_arraylist.get(index).getIsbnadi()));
        screenyazaradi.setText(kitap_arraylist.get(index).getYazaradi());
        screenyayintarihi.setText(String.valueOf( kitap_arraylist.get(index).getYayintarihi()));
        screenkitapdili .setText(kitap_arraylist.get(index).getKitabin_dili())   ;
        screenkitapturu.setText(String.valueOf( kitap_arraylist.get(index).getKitabin_turu()));
        screenbasimyili.setText(String.valueOf( kitap_arraylist.get(index).getBasimyili()));
        screenyayinevi.setText(String.valueOf( kitap_arraylist.get(index).getYayinevi()));
    }

    @FXML
    void kitapdilsec(ActionEvent event) {

    }

    @FXML
    void kitaptursec(ActionEvent event) {

    }

    @FXML
    void yayinevisec(ActionEvent event) {

    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        kitapdilid.setItems(FXCollections.observableArrayList("Türkçe","İngilizce","Fransızca","Japonca","Almanca"));
        kitapturid.setItems(FXCollections.observableArrayList("Masal","Roman","Hikaye","Fıkra","Biyografi"));
        yayineviid.setItems(FXCollections.observableArrayList("Alfa","Amazon","YKY","Can","Kök"));
        basimyiliid.setValueFactory(new SpinnerValueFactory.IntegerSpinnerValueFactory(1900,2022,1,1));
        yayintarihid.setValue(LocalDate.now());
        try{
            FileInputStream fis=new FileInputStream("kitapbilgileri.dat");
            ObjectInputStream ois=new ObjectInputStream(fis);
            kitap_arraylist= (ArrayList<kitap>) ois.readObject();
            ois.close();
            for (int i = 0; i <kitap_arraylist.size() ; i++) {
                kitapseccombobox.getItems().add(kitap_arraylist.get(i).getKitapadi());
            }
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}
