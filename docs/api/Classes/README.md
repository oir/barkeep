## barkeep::Animation




Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using AnimationStyle | **[Style](api/Classes/classbarkeep_1_1_animation.md#using-style)**  |


</span>

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(std::ostream & out =std::cout) |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([const](api/Classes/classbarkeep_1_1_counter.md)[Animation](api/Classes/classbarkeep_1_1_animation.md) & other) =default |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([Animation](api/Classes/classbarkeep_1_1_animation.md) && ) =default |
| | **[~Animation](api/Classes/classbarkeep_1_1_animation.md#function-~animation)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_animation.md#function-clone)**() const override |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[style](api/Classes/classbarkeep_1_1_animation.md#function-style)**(Style sty) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_animation.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_animation.md#function-interval)**(Duration pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_animation.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_animation.md#function-no_tty)**() |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_animation.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_)**() const override |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>


### Public Types Documentation

#### using Style

```cpp
using barkeep::Animation::Style =  AnimationStyle;
```


### Public Functions Documentation

#### function Animation

```cpp
inline Animation(
    std::ostream & out =std::cout
)
```


#### function Animation

```cpp
Animation(
    constAnimation & other
) =default
```


#### function Animation

```cpp
Animation(
    Animation && 
) =default
```


#### function ~Animation

```cpp
inline ~Animation()
```


#### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


#### function style

```cpp
inline auto & style(
    Style sty
)
```


#### function message

```cpp
inline auto & message(
    const std::string & msg
)
```


#### function interval

```cpp
inline auto & interval(
    Duration pd
)
```


#### function interval

```cpp
inline auto & interval(
    double pd
)
```


#### function no_tty

```cpp
inline auto & no_tty()
```


### Protected Functions Documentation

#### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```


**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered display 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


Render a display: animation, progress bar, etc. 


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


-------------------------------



## barkeep::AsyncDisplay


Base class to handle all asynchronous displays. 


`#include <barkeep.h>`

Inherited by [barkeep::Animation](api/Classes/classbarkeep_1_1_animation.md), [barkeep::Composite](api/Classes/classbarkeep_1_1_composite.md), [barkeep::Counter< Progress >](api/Classes/classbarkeep_1_1_counter.md), [barkeep::ProgressBar< Progress >](api/Classes/classbarkeep_1_1_progress_bar.md)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)**() const =0 |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)**(std::ostream & out) =0 |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)**() const =0 |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[message](api/Classes/classbarkeep_1_1_async_display.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**(Duration pd) |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd) |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty](api/Classes/classbarkeep_1_1_async_display.md#function-no_tty)**()<br>Enable no-tty mode.  |


</span>

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

### Friends

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>

### Public Functions Documentation

#### function AsyncDisplay

```cpp
inline AsyncDisplay(
    std::ostream & out =std::cout
)
```


#### function AsyncDisplay

```cpp
inline AsyncDisplay(
    constAsyncDisplay & other
)
```


#### function AsyncDisplay

```cpp
inline AsyncDisplay(
    AsyncDisplay && other
)
```


#### function ~AsyncDisplay

```cpp
inline virtual ~AsyncDisplay()
```


#### function show

```cpp
inline virtual void show()
```


**Reimplemented by**: [barkeep::Counter::show](api/Classes/classbarkeep_1_1_counter.md#function-show), [barkeep::ProgressBar::show](api/Classes/classbarkeep_1_1_progress_bar.md#function-show)


Start the display. This starts writing the display in the output stream, and computing speed if applicable. 


#### function done

```cpp
inline virtual void done()
```


End the display. This adds a newline to the output stream and stops writing. 


#### function clone

```cpp
virtual std::unique_ptr< AsyncDisplay > clone() const =0
```


**Reimplemented by**: [barkeep::Animation::clone](api/Classes/classbarkeep_1_1_animation.md#function-clone), [barkeep::Composite::clone](api/Classes/classbarkeep_1_1_composite.md#function-clone), [barkeep::Counter::clone](api/Classes/classbarkeep_1_1_counter.md#function-clone), [barkeep::ProgressBar::clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)


### Protected Functions Documentation

#### function render_

```cpp
virtual size_t render_(
    std::ostream & out
) =0
```


**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered display 

**Reimplemented by**: [barkeep::Animation::render_](api/Classes/classbarkeep_1_1_animation.md#function-render_), [barkeep::Composite::render_](api/Classes/classbarkeep_1_1_composite.md#function-render_), [barkeep::Counter::render_](api/Classes/classbarkeep_1_1_counter.md#function-render_), [barkeep::ProgressBar::render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)


Render a display: animation, progress bar, etc. 


#### function default_interval_

```cpp
virtual Duration default_interval_() const =0
```


**Reimplemented by**: [barkeep::Animation::default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_), [barkeep::Composite::default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_), [barkeep::Counter::default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_), [barkeep::ProgressBar::default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)


#### function display_

```cpp
inline void display_()
```

Display everything (message, maybe with animation, progress bar, etc). 

#### function render_message_

```cpp
inline size_t render_message_(
    std::ostream & out
) const
```


**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered message 

Display the message to output stream. 


#### function message

```cpp
inline void message(
    const std::string & msg
)
```


**Parameters**: 

  * **msg** message to be displayed 


Set message to be displayed 


#### function interval

```cpp
inline void interval(
    Duration pd
)
```


**Parameters**: 

  * **pd** interval as a Duration 


Set the interval in which the display is refreshed. This is also the interval in which speed is measured if applicable. 


#### function interval

```cpp
inline void interval(
    double pd
)
```


**Parameters**: 

  * **pd** interval as a double 


Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_async_display.md#function-interval) to accept a double argument 


#### function no_tty

```cpp
inline void no_tty()
```

Enable no-tty mode. 

### Protected Attributes Documentation

#### variable no_tty_

```cpp
bool no_tty_ = false;
```


### Friends

#### friend Composite

```cpp
friend class Composite(
    Composite 
);
```


-------------------------------



## barkeep::Composite




Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > left, std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > right) |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**([const](api/Classes/classbarkeep_1_1_counter.md)[Composite](api/Classes/classbarkeep_1_1_composite.md) & other) |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) && other) =default |
| | **[~Composite](api/Classes/classbarkeep_1_1_composite.md#function-~composite)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_composite.md#function-clone)**() const override |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_composite.md#function-no_tty)**() |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_composite.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_)**() const override |


</span>

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[left_](api/Classes/classbarkeep_1_1_composite.md#variable-left_)**  |
| std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[right_](api/Classes/classbarkeep_1_1_composite.md#variable-right_)**  |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[message](api/Classes/classbarkeep_1_1_async_display.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**(Duration pd) |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd) |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>


### Public Functions Documentation

#### function Composite

```cpp
inline Composite(
    std::unique_ptr< AsyncDisplay > left,
    std::unique_ptr< AsyncDisplay > right
)
```


#### function Composite

```cpp
inline Composite(
    constComposite & other
)
```


#### function Composite

```cpp
Composite(
    Composite && other
) =default
```


#### function ~Composite

```cpp
inline ~Composite()
```


#### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


#### function no_tty

```cpp
inline auto & no_tty()
```


### Protected Functions Documentation

#### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```


**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered display 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


Render a display: animation, progress bar, etc. 


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


### Protected Attributes Documentation

#### variable left_

```cpp
std::unique_ptr< AsyncDisplay > left_;
```


#### variable right_

```cpp
std::unique_ptr< AsyncDisplay > right_;
```


-------------------------------



## barkeep::Counter


 [More...](#detailed-description)

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, std::ostream & out =std::cout) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([const](api/Classes/classbarkeep_1_1_counter.md)[Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other) |
| | **[~Counter](api/Classes/classbarkeep_1_1_counter.md#function-~counter)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_counter.md#function-clone)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_counter.md#function-show)**() override |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed](api/Classes/classbarkeep_1_1_counter.md#function-speed)**(std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > discount) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed_unit](api/Classes/classbarkeep_1_1_counter.md#function-speed_unit)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_counter.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**(Duration pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_counter.md#function-no_tty)**() |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_counter.md#function-render_counts_)**(std::ostream & out) |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_counter.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_)**() const override |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[init](api/Classes/classbarkeep_1_1_counter.md#function-init)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(std::ostream & out =std::cout) |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>


### Detailed Description

```cpp
template <typenameProgress  =size_t>
class barkeep::Counter;
```

### Public Functions Documentation

#### function Counter

```cpp
inline Counter(
    Progress * progress,
    std::ostream & out =std::cout
)
```


#### function Counter

```cpp
inline Counter(
    constCounter< Progress > & other
)
```


#### function Counter

```cpp
inline Counter(
    Counter< Progress > && other
)
```


#### function ~Counter

```cpp
inline ~Counter()
```


#### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


#### function show

```cpp
inline virtual void show() override
```


**Reimplements**: [barkeep::AsyncDisplay::show](api/Classes/classbarkeep_1_1_async_display.md#function-show)


Start the display. This starts writing the display in the output stream, and computing speed if applicable. 


#### function speed

```cpp
inline auto & speed(
    std::optional< double > discount
)
```


#### function speed_unit

```cpp
inline auto & speed_unit(
    const std::string & msg
)
```


#### function message

```cpp
inline auto & message(
    const std::string & msg
)
```


#### function interval

```cpp
inline auto & interval(
    Duration pd
)
```


#### function interval

```cpp
inline auto & interval(
    double pd
)
```


#### function no_tty

```cpp
inline auto & no_tty()
```


### Protected Functions Documentation

#### function render_counts_

```cpp
inline size_t render_counts_(
    std::ostream & out
)
```


#### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```


**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered display 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


Render a display: animation, progress bar, etc. 


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function init

```cpp
inline void init(
    Progress * progress
)
```


#### function Counter

```cpp
inline Counter(
    std::ostream & out =std::cout
)
```


-------------------------------



## barkeep::ProgressBar


 [More...](#detailed-description)

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using ProgressBarStyle | **[Style](api/Classes/classbarkeep_1_1_progress_bar.md#using-style)**  |


</span>

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, std::ostream & out =std::cout) |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other) |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([const](api/Classes/classbarkeep_1_1_counter.md)[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other) |
| | **[~ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-~progressbar)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_progress_bar.md#function-show)**() override |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed](api/Classes/classbarkeep_1_1_progress_bar.md#function-speed)**(std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > discount) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed_unit](api/Classes/classbarkeep_1_1_progress_bar.md#function-speed_unit)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[total](api/Classes/classbarkeep_1_1_progress_bar.md#function-total)**([ValueType](api/Classes/classbarkeep_1_1_counter.md) tot) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[style](api/Classes/classbarkeep_1_1_progress_bar.md#function-style)**(Style sty) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_progress_bar.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval)**(Duration pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_progress_bar.md#function-no_tty)**() |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_progress_bar_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_progress_bar_)**(std::ostream & out) |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_counts_)**(std::ostream & out) |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_percentage_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_percentage_)**(std::ostream & out) |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)**() const override |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[init](api/Classes/classbarkeep_1_1_progress_bar.md#function-init)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress) |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**(std::ostream & out =std::cout) |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>


### Detailed Description

```cpp
template <typenameProgress >
class barkeep::ProgressBar;
```

### Public Types Documentation

#### using Style

```cpp
using barkeep::ProgressBar< Progress >::Style =  ProgressBarStyle;
```


### Public Functions Documentation

#### function ProgressBar

```cpp
inline ProgressBar(
    Progress * progress,
    std::ostream & out =std::cout
)
```


#### function ProgressBar

```cpp
inline ProgressBar(
    ProgressBar< Progress > && other
)
```


#### function ProgressBar

```cpp
inline ProgressBar(
    constProgressBar< Progress > & other
)
```


#### function ~ProgressBar

```cpp
inline ~ProgressBar()
```


#### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


#### function show

```cpp
inline virtual void show() override
```


**Reimplements**: [barkeep::AsyncDisplay::show](api/Classes/classbarkeep_1_1_async_display.md#function-show)


Start the display. This starts writing the display in the output stream, and computing speed if applicable. 


#### function speed

```cpp
inline auto & speed(
    std::optional< double > discount
)
```


#### function speed_unit

```cpp
inline auto & speed_unit(
    const std::string & msg
)
```


#### function total

```cpp
inline auto & total(
    ValueType tot
)
```


#### function style

```cpp
inline auto & style(
    Style sty
)
```


#### function message

```cpp
inline auto & message(
    const std::string & msg
)
```


#### function interval

```cpp
inline auto & interval(
    Duration pd
)
```


#### function interval

```cpp
inline auto & interval(
    double pd
)
```


#### function no_tty

```cpp
inline auto & no_tty()
```


### Protected Functions Documentation

#### function render_progress_bar_

```cpp
inline size_t render_progress_bar_(
    std::ostream & out
)
```


#### function render_counts_

```cpp
inline size_t render_counts_(
    std::ostream & out
)
```


#### function render_percentage_

```cpp
inline size_t render_percentage_(
    std::ostream & out
)
```


#### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```


**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered display 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


Render a display: animation, progress bar, etc. 


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function init

```cpp
inline void init(
    Progress * progress
)
```


#### function ProgressBar

```cpp
inline ProgressBar(
    std::ostream & out =std::cout
)
```


-------------------------------



## barkeep::Speedometer


 [More...](#detailed-description)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_speed](api/Classes/classbarkeep_1_1_speedometer.md#function-render_speed)**(std::ostream & out, [const](api/Classes/classbarkeep_1_1_counter.md) std::string & speed_unit) |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_speedometer.md#function-start)**() |
| | **[Speedometer](api/Classes/classbarkeep_1_1_speedometer.md#function-speedometer)**([Progress](api/Classes/classbarkeep_1_1_counter.md) & progress, [double](api/Classes/classbarkeep_1_1_counter.md) discount) |


</span>

### Detailed Description

```cpp
template <typenameProgress >
class barkeep::Speedometer;
```

### Public Functions Documentation

#### function render_speed

```cpp
inline size_t render_speed(
    std::ostream & out,
    const std::string & speed_unit
)
```


#### function start

```cpp
inline void start()
```


#### function Speedometer

```cpp
inline Speedometer(
    Progress & progress,
    double discount
)
```


-------------------------------



## barkeep::AtomicTraits


 [More...](#detailed-description)

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using [T](api/Classes/classbarkeep_1_1_counter.md) | **[value_type](api/Classes/structbarkeep_1_1_atomic_traits.md#using-value_type)**  |


</span>

### Detailed Description

```cpp
template <typenameT >
struct barkeep::AtomicTraits;
```

### Public Types Documentation

#### using value_type

```cpp
using barkeep::AtomicTraits< T >::value_type =  T;
```


-------------------------------



## barkeep::AtomicTraits< std::atomic< T > >


 [More...](#detailed-description)

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using [T](api/Classes/classbarkeep_1_1_counter.md) | **[value_type](api/Classes/structbarkeep_1_1_atomic_traits_3_01std_1_1atomic_3_01_t_01_4_01_4.md#using-value_type)**  |


</span>

### Detailed Description

```cpp
template <typenameT >
struct barkeep::AtomicTraits< std::atomic< T > >;
```

### Public Types Documentation

#### using value_type

```cpp
using barkeep::AtomicTraits< std::atomic< T > >::value_type =  T;
```


-------------------------------

Updated on 2023-12-01 at 22:33:53 -0500