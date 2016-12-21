package jp.keita.kagurazaka.jni.demo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import jp.keita.kagurazaka.jnisample.SomeNativeClassWrapper;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        SomeNativeClassWrapper wrapper = new SomeNativeClassWrapper();
        int result = wrapper.calculate();

        String message = "No error";
        try {
            wrapper.throwException();
        } catch (Exception e) {
            message = e.getMessage();
        }

        wrapper.close();

        TextView textView1 = (TextView) findViewById(R.id.text1);
        textView1.setText("Result: " + result);

        TextView textView2 = (TextView) findViewById(R.id.text2);
        textView2.setText(message);
    }
}
