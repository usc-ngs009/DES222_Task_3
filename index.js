import Module from './output.js';

const postCodeInput = document.getElementById("postCodeInput");

// This function is needed to translate between the "C-style" string that the C++ function returns,
// and a normal javascript string
function getStringFromMemory(ptr, wasmModule) {
    const memory = wasmModule.HEAPU8;
    let endPtr = ptr;
    while (memory[endPtr] !== 0) {
        endPtr++;
    }
    return new TextDecoder('utf-8').decode(memory.subarray(ptr, endPtr));
}

// This is a javascript wrapper for the Web Assembly export of the compiled C++ function
async function generateMessage(postCode) {
    const wasmModule = await Module();
    
    // Allocate memory in WebAssembly for the input string
    const lengthBytes = wasmModule.lengthBytesUTF8(postCode) + 1;
    const inputPointer = wasmModule._malloc(lengthBytes);
    
    // copy the postcode value to the allocated memory
    wasmModule.stringToUTF8(postCode, inputPointer, lengthBytes);
 
    // Call the C++ function with the pointer to the string
    const resultPointer = wasmModule._generateMessage(inputPointer);
    const result = getStringFromMemory(resultPointer, wasmModule);
    wasmModule._free(inputPointer);
   
    return result;    
}

// Simple example of entering postcode and displaying the corresponding message
postCodeInput.addEventListener('change', async (event) => {
    const msg = await generateMessage(event.target.value);
    document.getElementById('output').innerText = msg;
});
