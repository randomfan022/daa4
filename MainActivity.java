package com.example.prog4a4bcombined;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import android.annotation.SuppressLint;
import android.content.Intent;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
public class MainActivity extends AppCompatActivity {
 Button cam;
 Button gal;
 ImageView viewt;
 @SuppressLint("MissingInflatedId")
 @Override
 protected void onCreate(Bundle savedInstanceState) {
 super.onCreate(savedInstanceState);
 setContentView(R.layout.activity_main);
 cam=findViewById(R.id.cam);
 gal=findViewById(R.id.Gallery);
 viewt=findViewById(R.id.imageView);
 cam.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v) {
 Intent in = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
 startActivityForResult(in,100);
 }
 });
 gal.setOnClickListener(new View.OnClickListener() {
 @Override
 public void onClick(View v) {
 Intent in= new 
Intent(Intent.ACTION_PICK).setData(MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
 startActivityForResult(in, 101);
 }
 });
 }
 @Override
 protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
 super.onActivityResult(requestCode, resultCode, data);
 if(resultCode==RESULT_OK)
 {
 if(requestCode==100)
 {
 Bitmap img=(Bitmap)(data.getExtras().get("data"));
 viewt.setImageBitmap(img);
 }
 if(requestCode==101)
 {
 viewt.setImageURI(data.getData());
 }
 }
 }
}
