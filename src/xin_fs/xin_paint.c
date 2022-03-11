

#include <lib/stdiox.h>
#include <xin_fs/xin.c>
#include <lib/memory.h>
#include <lib/exit_process.h>
#include <lib/string.h>

#define VGA_SCREEN_RESOLUTION 4480

void xin_paint(char* file_name)
{
    clearScr();
    no_enter = true;
    in_graphic_mode = true;
    print_off = true;


    xin_entry* xin_file = xin_find_entry(file_name);
    
    if(xin_file == nullptr)
    {
        xprintf("%zno such file or directory %s\n",set_output_color(red,white),program_parameters);
        
        while(1)
        {
            if(keyboard_scan_code == ENTER)
            {
                arrows_navigate = false;
                exit_process();
            }
        }   
    
    }
        
    else
    {
    
            
        if(xin_file->entry_type == XIN_DIRECTORY)
        {
            xprintf("%zyou cant edit directory\n",set_output_color(red,white));
            xprintf("%zuse F4 key to exit\n",set_output_color(red,white));
            while(keyboard_scan_code != ENTER);
            exit_process();
        }


        char* data_pointer;

        {
            for(char* i = (char*)(xin_file->starting_sector * SECTOR_SIZE);  i < (char*)(xin_file->starting_sector + VGA_SCREEN_RESOLUTION); i++)
            {
                xprintf("%z ", set_output_color(*i >> 4, *i & 0x0F));
            }
        }


        cursor = (uint16_t*)(VGA_TEXT_MEMORY);
        


        while(keyboard_scan_code != F4_KEY)
        {

            switch(getchar())
            {
                case '0': *cursor = (uint16_t) (0x20 + (((black << 4) | black) << 8));break;
                case '1': *cursor = (uint16_t) (0x20 + (((blue << 4) | black) << 8));break;
                case '2': *cursor = (uint16_t) (0x20 + (((green << 4) | black) << 8));break;
                case '3': *cursor = (uint16_t) (0x20 + (((cyan << 4) | black) << 8));break;
                case '4': *cursor = (uint16_t) (0x20 + (((red << 4) | black) << 8));break;
                case '5': *cursor = (uint16_t) (0x20 + (((magenta << 4) | black) << 8));break;
                case '6': *cursor = (uint16_t) (0x20 + (((brown << 4) | black) << 8));break;
                case '7': *cursor = (uint16_t) (0x20 + (((lgray << 4) | black) << 8));break;
                case '8': *cursor = (uint16_t) (0x20 + (((dgray << 4) | black) << 8));break;
                case '9': *cursor = (uint16_t) (0x20 + (((lblue << 4) | black) << 8));break;
                case 'a': *cursor = (uint16_t) (0x20 + (((lgreen << 4) | black) << 8));break;
                case 'b': *cursor = (uint16_t) (0x20 + (((lcyan << 4) | black) << 8));break;
                case 'c': *cursor = (uint16_t) (0x20 + (((lred << 4) | black) << 8));break;
                case 'd': *cursor = (uint16_t) (0x20 + (((lmagenta << 4) | black) << 8));break;
                case 'e': *cursor = (uint16_t) (0x20 + (((yellow << 4) | black) << 8));break;
                case 'f': *cursor = (uint16_t) (0x20 + (((white << 4) | black) << 8));break;
                default: break;
            }



        }


        uint32_t file_data_counter = 0x0;

        data_pointer = (char*)(xin_file->starting_sector * SECTOR_SIZE);

        for(char* i = (char*)VGA_TEXT_MEMORY; 
                (uint32_t)i < VGA_TEXT_MEMORY + VGA_SCREEN_RESOLUTION; i+=2)
                if(*i == '\0')
                    *i = 0x20;

        for(char* i = (char*)VGA_TEXT_MEMORY; 
                (uint32_t)i < VGA_TEXT_MEMORY + VGA_SCREEN_RESOLUTION; i+=2, file_data_counter++)
                data_pointer[file_data_counter] = *i;

        xin_file->entry_size = file_data_counter;


    }

    
    exit_process();
}