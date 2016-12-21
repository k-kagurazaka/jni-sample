package jp.keita.kagurazaka.spring.demo

import jp.keita.kagurazaka.jnisample.SomeNativeClassWrapper
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController

@RestController
class DemoController {
    @RequestMapping("/demo")
    fun demo(): String {
        SomeNativeClassWrapper().use {
            val result = it.calculate()
            var message = "No Error"
            try {
                it.throwException()
            } catch (e: Exception) {
                message = e.message ?: "Unknown Error"
            }

            return "Result: $result\nMessage:$message"
        }
    }
}
